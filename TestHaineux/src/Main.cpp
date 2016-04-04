//
// Thread.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 16:01:55 2016 guillaume wilmot
// Last update Mon Apr  4 20:45:12 2016 guillaume wilmot
//

#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include "Thread.hpp"
#include "Mutex.hpp"
#include "ScopedLock.hpp"

Mutex			mutex;

void			*inc(void *arg)
{
  ScopedLock		lock(mutex);
  int			**conv;
  int			*c;

  conv = (int **)arg;
  c = conv[0];
  *c += *conv[1];
  return (NULL);
}

int			main(int ac, char **av)
{
  Thread		*thread;
  int			c = 0;
  int			x;
  int			i;
  int			*arg[2];

  if (ac < 3)
    return (-1);
  thread = new Thread[atoi(av[2])];
  x = atoi(av[1]);
  arg[0] = &c;
  arg[1] = &x;
  for (i = 0; i < atoi(av[2]); i++)
    thread[i].start(&inc, &arg);
  for (i = 0; i < atoi(av[2]); i++)
    thread[i].join();
  std::cout << c << std::endl;
  delete[] thread;
}
