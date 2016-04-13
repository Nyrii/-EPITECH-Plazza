//
// Core.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:58:09 2016 Florian Saurs
// Last update Wed Apr 13 21:57:54 2016 Florian Saurs
//

#include <fstream>
#include "Core.hpp"
#include "Parsing.hpp"
#include "ClientSocketLocal.hpp"
#include "ServeurSocketLocal.hpp"
#include "ClientSocket.hpp"
#include "ServeurSocket.hpp"
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

  pars.read(this, INTERNET_SOCKET);
}

void				Core::execParse(std::string fileName, type _type) const
{
  ReadAndFind			raf;

  raf.execute(fileName, _type);
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
    t_processState	*struc = new t_processState;

    std::cout << "fill it " << std::endl;
    memset(struc, 0, sizeof(*struc));
    struc->id = 0;
    struc->free = false;
    struc->fileName = new std::string(fileName);
    _sonTab[pid]->write(*struc);
}

void			Core::launchWorkNP(std::string fileName, NamedPipe *serv, type _type)
{
    t_processState	*struc = new t_processState;
    int			retRead;

    _isFinished = false;
    while (_isFinished == false)
      {
	memset(struc, 0, sizeof(*struc));
	struc->id = 0;
      	struc->free = false;
      	struc->fileName = new std::string("");
	serv->write(*struc);
	execParse(fileName, _type);
        struc->free = true;
	serv->write(*struc);
	if ((retRead = serv->read(*struc)) == 0 && struc->id == 0)
	  fileName = *(struc->fileName);
	else if ((retRead == 0 && struc->id == -1) || retRead == -1)
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
	  launchWorkNP(fileName, serv, _type);
	serv->read(struc);
        _sonTab.insert(std::pair<int, ICommunication *>(id, serv));
      }
}

// void			Core::launchWorkSocket(std::string fileName, type _type, int id)
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
// void			Core::runProcessSocket(std::string fileName, type _type, Communication)
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

void			Core::launchWorkSocket(std::string fileName, type _type, int id)
{
    t_processState	*struc = new t_processState;
    int			retRead;
    ClientSocket	*client = new ClientSocket();

    client->create(id);
    _isFinished = false;
    while (_isFinished == false)
      {
	memset(struc, 0, sizeof(*struc));
        struc->id = 0;
	struc->free = false;
	struc->fileName = new std::string("");
	client->write(*struc);
	execParse(fileName, _type);
	struc->free = true;
	client->write(*struc);
	std::cout << "read in son just now" << std::endl;
	if ((retRead = client->read(*struc)) == 0 && struc->id == 0)
	  fileName = *(struc->fileName);
	else if ((retRead == 0 && struc->id == -1) || retRead == -1)
	  _isFinished = true;
      }
    exit (0);
}

void			Core::runProcessSocket(std::string fileName, type _type, Communication)
{
    int			pid;
    static int		id = -1;
    t_processState	struc;
    static ServeurSocket	*serv = new ServeurSocket();

    if (_sonTab.size() != 0 && (pid = checkAvailable()) != 0)
      fillIt(pid, fileName);
    else
      {
	if (id == -1)
	  serv->create(++id);
	pid = fork();
	if (pid == 0)
	  launchWorkSocket(fileName, _type, id);
	serv->read(struc);
        _sonTab.insert(std::pair<int, ICommunication *>(id, serv));
      }
}
