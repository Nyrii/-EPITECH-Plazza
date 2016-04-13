//
// Core.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:58:09 2016 Florian Saurs
// Last update Wed Apr 13 14:34:56 2016 Nyrandone Noboud-Inpeng
//

#include <fstream>
#include "Core.hpp"
#include "Parsing.hpp"
#include "ClientSocketLocal.hpp"
#include "ServeurSocketLocal.hpp"
#include "Process.hpp"
#include "NamedPipe.hh"
#include "ReadAndFind.hh"

Core::Core(int nbThreads)
{
  _nbThreads = nbThreads;
}

Core::~Core()
{
  for (std::map<int, ICommunication *>::iterator it = _sonTab.begin(); it != _sonTab.end(); it++)
    it->second->destroy();
}

void		Core::read() const
{
  Parsing	pars;

  pars.read(this, NAMED_PIPE);
}

int			Core::checkAvailable() const
{
  t_processState	state;

  for (std::map<int, ICommunication *>::const_iterator it = _sonTab.begin(); it != _sonTab.end(); ++it)
    if ((it->second)->read(state) == 0 || state.free == true)
      return (it->first);
    return (0);
}

void			Core::fillIt(int pid, std::string fileName)
{
    t_processState	state;

    state = {0, false, fileName};
    _sonTab[pid]->write(state);
}

void			Core::launchWork(std::string fileName, NamedPipe *serv, type _type)
{
    t_processState	struc;
    int			retRead;
    ReadAndFind		raf;

    _isFinished = false;
    while (_isFinished == false)
      {
        struc = {getpid(), false, fileName};
	serv->write(struc);
	raf.execute(fileName, _type); // llllllllllllllllllllll
        struc = {getpid(), true, fileName};
	serv->write(struc);
	if ((retRead = serv->read(struc)) == 0 && struc.id == 0)
	  fileName = struc.fileName;
	else if ((retRead == 0 && struc.id == -1) || retRead == -1)
	  _isFinished = true;
      }
    exit (0);
}

void			Core::runProcessNP(std::string fileName, type _type, Communication)
{
    int			pid;
    static int		id = -1;
    t_processState	struc;

    if (_sonTab.size() != 0 && (pid = checkAvailable()) != 0)
      fillIt(pid, fileName);
    else
      {
	NamedPipe	*serv = new NamedPipe();

	serv->create(++id);
	pid = fork();
	if (pid == 0)
	  launchWork(fileName, serv, _type);
	serv->read(struc);
        _sonTab.insert(std::pair<int, ICommunication *>(id, serv));
      }
}

void			Core::runProcessSocket(std::string fileName, type _type, Communication)
{
    int			pid;
    static int		id = -1;
    t_processState	struc;

    if (_sonTab.size() != 0 && (pid = checkAvailable()) != 0)
      fillIt(pid, fileName);
    else
      {
	NamedPipe	*serv = new NamedPipe();

	serv->create(++id);
	pid = fork();
	if (pid == 0)
	  launchWork(fileName, serv, _type);
	serv->read(struc);
        _sonTab.insert(std::pair<int, ICommunication *>(struc.id, serv));
      }
}
