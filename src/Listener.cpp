//
// Listener.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:58:38 2016 guillaume wilmot
// Last update Fri Apr 15 22:16:59 2016 guillaume wilmot
//

/**/
#include <unistd.h>
/**/
#include <cstring>
#include <iostream>
#include "Listener.hpp"
#include "ThreadPool.hpp"
#include "ReadAndFind.hh"

Listener::Listener()
{
  _com = NULL;
  _nbThread = 0;
}

void			Listener::init(int nbThread, ICommunication *com)
{
  _nbThread = nbThread;
  _com = com;
}

t_processState		*Listener::getTask()
{
  t_processState	*struc;

  struc = new t_processState;
  /**/
  struc->fileName = std::string("\033[01;32m") + std::string("Fernand") + std::string("\033[0m");
  struc->info = PHONE_NUMBER;
  /**/
  return (struc);
}

bool			timeOut()
{
  return (true);
}

void			*Listener::listen()
{
  ThreadPool		threadPool(_nbThread);
  t_processState	*struc;

  threadPool.init(&CondThread::begin);
  while ((struc = getTask()) && !timeOut())
    {
      threadPool.queue(&ReadAndFind::execute, struc->info, struc->fileName);
      sleep(1);
    }
  exit(0);
  return (NULL);
}

void			*Listener::start(void *args)
{
  Listener		_this;
  t_processArgs		*tab;

  tab = reinterpret_cast<t_processArgs *>(args);
  _this.init(tab->nbThread, tab->com);
  return (_this.listen());
}
