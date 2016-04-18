//
// Core.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:58:09 2016 Florian Saurs
// Last update Mon Apr 18 21:57:42 2016 Florian Saurs
//

#include <fstream>
#include <signal.h>
#include "Core.hpp"
#include "Parsing.hpp"
#include "Sockets.hpp"
#include "SocketsLocal.hpp"
#include "Listener.hpp"
#include "ReadAndFind.hh"
#include "Pipes.hpp"
#include "CommunicationError.hh"

Core::Core(int nbThreads)
{
  signal(SIGINT, &sigHandler);
  signal(SIGCHLD, SIG_IGN);
  _nbThreads = nbThreads;
  setSonTab(&_sonTab);
  _communicationTab.insert(std::pair<Communication, void (Core:: *)(int &)>(NAMED_PIPE, &Core::createPipes));
  _communicationTab.insert(std::pair<Communication, void (Core:: *)(int &)>(INTERNET_SOCKET, &Core::createSockets));
  _communicationTab.insert(std::pair<Communication, void (Core:: *)(int &)>(LOCAL_SOCKET, &Core::createSocketsLocal));
}

Core::~Core()
{
  for (unsigned int i = 0; i < _sonTab.size(); i++)
    {
      try {
	delete _sonTab[i];
      } catch (const CommunicationError &e) {
	std::cerr << e.what() << std::endl;
      }
    }
}

void		Core::read(Communication com) const
{
  Parsing	parser;

  parser.read(this, com);
}

void			Core::runProcess(std::string fileName, Information info, Communication com)
{
  for (unsigned int i = 0; i < _sonTab.size(); i++)
    try {
      if (_sonTab[i]->checkAvailable())
	if (_sonTab[i]->assign(fileName, info) == true)
	  return;
    } catch (const CommunicationError &e) {
      std::cerr << e.what() << std::endl;
      try {
	_sonTab.erase(_sonTab.begin() + i);
      } catch (const CommunicationError &e) {
	std::cerr << e.what() << std::endl;
      }
    }

  static int		id = 0;

  (this->*this->_communicationTab[com])(id);

  Process		*process = new Process(_com);
  t_processArgs		args;

  args.com = _com;
  args.nbThread = _nbThreads;
  _sonTab.push_back(process);
  process->create(&Listener::start, &args);
  process->assign(fileName, info);
}

void		Core::createPipes(int &id)
{
  _com = new Pipes(id++);
}

void		Core::createSockets(int &id)
{
  std::vector<Process *>		*_sonTab;
  Sockets				*tmp;

  tmp = NULL;
  if ((_sonTab = getSonTab(NULL)))
    if (_sonTab->size() != 0)
      tmp = dynamic_cast<Sockets *>(_sonTab->at(0)->getCom());
  if (tmp == NULL)
    _com = new Sockets(id);
  else
    _com = new Sockets(tmp->getServeurSocket());
}

void		Core::createSocketsLocal(int &id)
{
  _com = new SocketsLocal(id++);
}

void					Core::setSonTab(std::vector<Process *> *sonTab)
{
  getSonTab(sonTab);
}

std::vector<Process *>			*Core::getSonTab(std::vector<Process *> *sonTab)
{
  static std::vector<Process *>		*_sonTab = NULL;

  _sonTab = sonTab ? sonTab : _sonTab;
  return (_sonTab);
}

void					Core::sigHandler(int)
{
  std::vector<Process *>		*_sonTab;

  signal(SIGINT, SIG_IGN);
  if ((_sonTab = getSonTab(NULL)))
    for (unsigned int i; i < _sonTab->size(); i++)
      {
	if ((*_sonTab)[i]->getPid() > 0)
	  kill((*_sonTab)[i]->getPid(), SIGUSR1);
	try {
	  delete (*_sonTab)[i];
	} catch (const CommunicationError &e) {
	  std::cerr << e.what() << std::endl;
	}
      }
  _exit(EXIT_SUCCESS);
}
