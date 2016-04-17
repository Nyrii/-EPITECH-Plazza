//
// Core.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:58:09 2016 Florian Saurs
// Last update Sun Apr 17 17:04:45 2016 guillaume wilmot
//

#include <fstream>
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
  _nbThreads = nbThreads;
}

Core::~Core()
{
  for (unsigned int i = 0; i < _sonTab.size(); i++)
    delete _sonTab[i];
}

void		Core::read() const
{
  Parsing	parser;

  parser.read(this, NAMED_PIPE);
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

void			Core::runProcessNP(std::string fileName, Information info, Communication)
{
  for (unsigned int i = 0; i < _sonTab.size(); i++)
    try {
      if (_sonTab[i]->checkAvailable())
	if (_sonTab[i]->assign(fileName, info) == true)
	  return;
    } catch (CommunicationError &e) {
      std::cerr << e.what() << std::endl;
      try {
	_sonTab.erase(_sonTab.begin() + i);
      } catch (CommunicationError &e) {
	std::cerr << e.what() << std::endl;
      }
    }

  // ATTENTION A L'ID
  static int		id = 0;
  ICommunication	*com = new Pipes(id++);
  Process		*process = new Process(com);
  t_processArgs		args;

  args.com = com;
  args.nbThread = _nbThreads;
  process->create(&Listener::start, &args);
  _sonTab.push_back(process);
  process->assign(fileName, info);
}

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


//   ReadAndFind			raf;
//   t_queue			args;

//   args.args->file = fileName;
//   args.args->order = _type;
//   args.args->callback = NULL;
//   args.ptr = &execute;
//   raf.execute(NULL);


void			Core::runProcessSocket(std::string, Information, Communication)
{}
