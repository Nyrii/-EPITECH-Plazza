//
// Listener.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:58:38 2016 guillaume wilmot
// Last update Fri Apr 15 22:04:54 2016 Florian Saurs
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
  _id = 0;
  _nbThread = 0;
}

void			Listener::init(int nbThread, int id)
{
  _nbThread = nbThread;
  _id = id;
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

void			*Listener::listen()
{
  ThreadPool		threadPool(_nbThread);
  t_processState	*struc;

  threadPool.init(&CondThread::begin);
  while ((struc = getTask()))
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
  int			*tab;

  tab = reinterpret_cast<int *>(args);
  _this.init(tab[0], tab[1]);
  return (_this.listen());
}
