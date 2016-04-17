//
// Listener.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:58:38 2016 guillaume wilmot
// Last update Sun Apr 17 17:48:15 2016 Nyrandone Noboud-Inpeng
//

/**/
#include <unistd.h>
/**/
#include <cstring>
#include <iostream>
#include "Listener.hpp"
#include "ReadAndFind.hh"
#include "CommunicationError.hh"

Listener::Listener()
{
  _com = NULL;
  _nbThread = 0;
  _timer.setTime(5);
}

void			Listener::init(int nbThread, Com *com)
{
  _nbThread = nbThread;
  _com = com;
}

t_processState		*Listener::getTask(ThreadPool &threadPool)
{
  t_processState	*struc;

  struc = new t_processState;
  memset(struc, 0, sizeof(*struc));
  if (_com->read(*struc) == -1)
    {
      delete struc;
      return (NULL);
    }
  if (struc->state == ASSIGN)
    {
      _com->write(*struc);
      return (struc);
    }
  if (struc->state == FREE)
    {
      struc->free = threadPool.getTotalOrders() < _nbThread * 2 ? true : false;
      _com->write(*struc);
    }
  delete struc;
  return (NULL);
}

bool			Listener::timeOut()
{
  if (_timer.isElapsed())
    return (true);
  return (false);
}

void			*Listener::listen()
{
  ThreadPool		threadPool(_nbThread);
  t_processState	*struc;

  threadPool.init(&CondThread::begin);
  threadPool.setTimer(&_timer);
  while (1)
    {
      try {
	if ((struc = getTask(threadPool)))
	  {
	    threadPool.queue(&ReadAndFind::execute, struc->info, struc->fileName);
	    delete struc;
	  }
      } catch (CommunicationError &e) {
	std::cerr << "Pausing" << std::endl;
	pause();
      }
    }
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
