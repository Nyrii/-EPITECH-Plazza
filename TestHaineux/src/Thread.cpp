//
// Thread.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 16:01:55 2016 guillaume wilmot
// Last update Mon Apr  4 19:04:21 2016 guillaume wilmot
//

#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include "Mutex.hpp"

Mutex			mutex;

void			*inc(void *arg)
{
  int			**conv;
  int			*c;

  mutex.lock();
  conv = (int **)arg;
  c = conv[0];
  *c += *conv[1];
  mutex.unlock();
  return (NULL);
}

int			main(int ac, char **av)
{
  pthread_t		thread[10];
  int			c = 0;
  int			x;
  int			i;
  int			*arg[2];

  if (ac < 3)
    return (-1);
  x = atoi(av[1]);
  arg[0] = &c;
  arg[1] = &x;
  for (i = 0; i < atoi(av[2]); i++)
    pthread_create(&thread[i], NULL, &inc, &arg);
  for (i = 0; i < atoi(av[2]); i++)
    pthread_join(thread[i], NULL);
  std::cout << c << std::endl;
}
