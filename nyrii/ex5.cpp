//
// ex5.cpp for ex5 in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 23:12:19 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 23:42:11 2016 Nyrandone Noboud-Inpeng
//

#include <pthread.h>
#include <iostream>
#include <sstream>
#include "mutex.hpp"
#include "ScopedLock.hpp"
#include "Thread.hpp"
#include "SafeQueue.hpp"

Mutex	mutex;
int	return_value;

SafeQueue::SafeQueue()
{
  _isFinished = false;
}

SafeQueue::~SafeQueue()
{

}

void	SafeQueue::push(int value)
{
  _stack.push(value);
}

bool	SafeQueue::tryPop(int *value)
{
  if (_stack.empty())
    return (false);
  *value = _stack.top();
  _stack.pop();
  return (true);
}

bool	SafeQueue::isFinished()
{
  if (_isFinished && _stack.empty())
    return (true);
  return (false);
}

void	SafeQueue::setFinished()
{
  _isFinished = true;
}

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
