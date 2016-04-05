//
// ex4.cpp for ex4 in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 22:04:27 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 23:10:13 2016 Nyrandone Noboud-Inpeng
//

#include <pthread.h>
#include <iostream>
#include <sstream>
#include "mutex.hpp"
#include "ScopedLock.hpp"
#include "Thread.hpp"

Mutex	mutex;
int	return_value;

Thread::Thread()
{
  _status = STANDBY;
}

Thread::~Thread()
{
}

void		Thread::start(void *(*fptr)(void *))
{
  pthread_create(&_pth, NULL, fptr, &return_value);
  _status = RUNNING;
}

void		Thread::waitDeath()
{
  pthread_join(_pth, NULL);
  _status = DEAD;
}

ScopedLock::ScopedLock(Mutex &tmp_mutex)
{
  _mutex = &tmp_mutex;
  _mutex->lock();
}

ScopedLock::~ScopedLock()
{
  _mutex->unlock();
}

Mutex::Mutex()
{
  pthread_mutex_init(&_mutex, NULL);
}

Mutex::~Mutex()
{

}

void	Mutex::lock(void)
{
  pthread_mutex_lock(&_mutex);
}

void	Mutex::unlock(void)
{
  pthread_mutex_unlock(&_mutex);
}

bool	Mutex::trylock(void)
{
  if (pthread_mutex_lock(&_mutex))
    {
      return (true);
    }
  return (false);
}

void		*increment_counter(void *N)
{
  ScopedLock	lock(mutex);

  *(int *)N += 1;
  return (N);
}

int			main(int argc, char **argv)
{
  int			i;
  int			nbThread;
  std::stringstream	os;

  if (argc != 2)
    return (-1);
  i = 0;
  os << argv[1];
  os >> nbThread;
  Thread		*pth = new Thread[nbThread + 1];
  while (i < nbThread)
    pth[i++].start(&increment_counter);

  i = 0;
  while (i < nbThread)
    pth[i++].waitDeath();

  std::cout << return_value << std::endl;

  delete[] pth;
  return (0);
}
