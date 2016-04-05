//
// ex3.cpp for ex3 in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 21:29:51 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 22:02:48 2016 Nyrandone Noboud-Inpeng
//

#include <pthread.h>
#include <iostream>
#include <sstream>
#include "mutex.hpp"
#include "ScopedLock.hpp"

Mutex	mutex;

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

void	*increment_counter(void *N)
{
  ScopedLock lock(mutex);

  *(int *)N += 1;
  return (N);
}

int		main(int argc, char **argv)
{
  pthread_t	pth[50];
  int		return_value;
  int		i;
  int		nbThread;
  std::stringstream	os;

  if (argc != 2)
    return (-1);
  i = 0;
  os << argv[1];
  os >> nbThread;
  while (i < nbThread)
    pthread_create(&pth[i++], NULL, &increment_counter, &return_value);

  i = 0;
  while (i < nbThread)
    pthread_join(pth[i++], NULL);

  std::cout << return_value << std::endl;
  return (0);
}
