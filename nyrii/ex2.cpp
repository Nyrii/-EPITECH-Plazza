//
// ex2.cpp for ex2 in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 21:19:03 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 21:27:42 2016 Nyrandone Noboud-Inpeng
//

#include <pthread.h>
#include <iostream>
#include <sstream>
#include "mutex.hpp"

Mutex	mutex;

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
    if (pthread_mutex_lock(&_mutex)) {
      return (true);
    }
  return (false);
}

void	*increment_counter(void *N)
{
  mutex.lock();
  *(int *)N += 1;
  mutex.unlock();
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
