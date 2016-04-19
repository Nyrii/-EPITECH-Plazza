//
// Core.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:58:09 2016 Florian Saurs
// Last update Mon Apr 18 05:41:16 2016 guillaume wilmot
//

#include <fstream>
#include <signal.h>
#include "Core.hpp"
#include "Parsing.hpp"
#include "ClientSocketLocal.hpp"
#include "ServeurSocketLocal.hpp"
#include "ClientSocket.hpp"
#include "ServeurSocket.hpp"
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

void		Core::read() const
{
  Parsing	parser;

  parser.read(this, NAMED_PIPE);
}

void			Core::runProcessNP(std::string fileName, Information info, Communication)
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
  Com			*com = new Pipes(id++);
  Process		*process = new Process(com);
  t_processArgs		args;

  args.com = com;
  args.nbThread = _nbThreads;
  _sonTab.push_back(process);
  process->create(&Listener::start, &args);
  process->assign(fileName, info);
}

// void			Core::launchWorkNP(std::string fileName, NamedPipe *serv, Information _type)
// {
//     t_processState	*struc = new t_processState;
//     int			retRead;

//     _isFinished = false;
//     while (_isFinished == false)
//       {
// 	memset(struc, 0, sizeof(*struc));
// 	struc->id = 0;
//       	struc->free = false;
//       	struc->fileName = new std::string("");
// 	serv->write(*struc);
// 	execParse(fileName, _type);
//         struc->free = true;
// 	serv->write(*struc);
// 	if ((retRead = serv->read(*struc)) == 0 && struc->id == 0)
// 	  fileName = *(struc->fileName);
// 	else if ((retRead == 0 && struc->id == -1) || retRead == -1)
// 	  _isFinished = true;
//       }
//     exit(0);
// }

// void			Core::launchWorkSocket(std::string fileName, Information _type, int id)
// {
//     t_processState	struc;
//     int			retRead;
//     ClientSocketLocal	*client = new ClientSocketLocal();
//
//     client->create(id);
//     _isFinished = false;
//     while (_isFinished == false)
//       {
//         struc = {getpid(), false, fileName};
// 	client->write(struc);
// 	execParse(fileName, _type);
//         struc = {getpid(), true, fileName};
// 	client->write(struc);
// 	if ((retRead = client->read(struc)) == 0 && struc.id == 0)
// 	  fileName = struc.fileName;
// 	else if ((retRead == 0 && struc.id == -1) || retRead == -1)
// 	  _isFinished = true;
//       }
//     exit (0);
// }
//
// void			Core::runProcessSocket(std::string fileName, Information _type, Communication)
// {
//     int			pid;
//     static int		id = -1;
//     t_processState	struc;
//
//     if (_sonTab.size() != 0 && (pid = checkAvailable()) != 0)
//       fillIt(pid, fileName);
//     else
//       {
// 	ServeurSocketLocal	*serv = new ServeurSocketLocal();
//
// 	serv->create(++id);
// 	pid = fork();
// 	if (pid == 0)
// 	  launchWorkSocket(fileName, _type, id);
// 	serv->read(struc);
//         _sonTab.insert(std::pair<int, ICommunication *>(id, serv));
//       }
// }

void			Core::launchWorkSocket(std::string fileName, Information // _type
					       , int id)
{
    t_processState	*struc = new t_processState;
    int			retRead;
    ClientSocket	*client = new ClientSocket();
    ReadAndFind		raf;

    client->create(id);
    _isFinished = false;
    while (_isFinished == false)
      {
	memset(struc, 0, sizeof(*struc));
        struc->id = 0;
	struc->free = false;
        memset(struc->fileName, 0, sizeof(struc->fileName));
	client->write(*struc);
	raf.execute(NULL// fileName, _type
		    );
	struc->free = true;
	client->write(*struc);
	std::cout << "read in son just now" << std::endl;
	if ((retRead = client->read(*struc)) > 0 && struc->id == 0)
	  fileName = struc->fileName;
	else if ((retRead > 0 && struc->id == -1) || retRead == -1)
	  _isFinished = true;
      }
    exit (0);
}

void			Core::runProcessSocket(std::string, Information, Communication) {}

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
    for (unsigned int i = 0; i < _sonTab->size(); i++)
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
