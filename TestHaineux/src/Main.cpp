//
// Thread.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 16:01:55 2016 guillaume wilmot
// Last update Mon Apr  4 22:02:29 2016 guillaume wilmot
//

#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include "Thread.hpp"
#include "Mutex.hpp"
#include "ScopedLock.hpp"
#include "SafeQueue.hpp"

SafeQueue		test;

void			*push(void *)
{
  test.push(rand() % 100);
  return (NULL);
}

void			*pop(void *)
{
  int			i;

  if (!test.tryPop(&i))
    std::cout << "false" << std::endl;
  else
    std::cout << i << std::endl;
  return (NULL);
}

int			main(int ac, char **av)
{
  Thread		*thread;
  int			nbThread;
  int			i;

  if (ac < 2)
    return (-1);
  nbThread = atoi(av[1]);
  thread = new Thread[nbThread * 2];
  for (i = 0; i < nbThread / 2; i++)
    thread[i].start(&push, NULL);
  test.setFinished();
  while (i < nbThread)
    {
      thread[i].start(&push, NULL);
      i++;
    }
  for (i = 0; i < nbThread; i++)
    thread[nbThread + i].start(&pop, NULL);
  for (i = 0; i < nbThread * 2; i++)
    thread[i].join();
  delete[] thread;
}
