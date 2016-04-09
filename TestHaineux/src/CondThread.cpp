//
// CondThread.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 18:19:02 2016 guillaume wilmot
// Last update Fri Apr  8 19:21:21 2016 guillaume wilmot
//

#include "ScopedLock.hpp"
#include "CondThread.hpp"
#include <unistd.h>

CondThread::CondThread() : _cond(_mutex)
{
  _order.set(NULL);
}

bool		CondThread::isWorking()
{
  return (_order.get() ? true : false);
}

void		CondThread::assignOrder(t_queue *order)
{
  ScopedLock	lock(_mutex);

  _order.set(order);
  _cond.signal();
  std::cout << "Woke up" << std::endl;
}

void		*CondThread::listen()
{
  ScopedLock	lock(_mutex);
  void		*ret;
  t_queue	*del;

  while (1)
    {
      _cond.wait();
      if (_order.get())
  	{
  	  ret = _order.get()->ptr(_order.get()->args);
  	  if (ret)
	    {
	      delete _order.get()->args;
	      delete _order.get();
	      return (NULL);
	    }
	  del = _order.get();
	  del->args->callback->callback();
	  delete del->args;
	  delete del;
	  _order.set(NULL); // PROBLEMATIC
  	}
    }
}

void		*CondThread::begin(void *args)
{
  CondThread	*condThread;

  condThread = reinterpret_cast<CondThread *>(args);
  return (condThread->listen());
}
