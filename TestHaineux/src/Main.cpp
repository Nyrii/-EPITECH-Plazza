//
// Thread.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 16:01:55 2016 guillaume wilmot
// Last update Tue Apr  5 14:36:39 2016 guillaume wilmot
//

#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include "Thread.hpp"
#include "Mutex.hpp"
#include "ScopedLock.hpp"
#include "SafeQueue.hpp"

SafeQueue		test;

void			*producer(void *)
{
  while (42)
    {
      test.push(rand() % 100);
      usleep(rand() % 100000);
      if (test.isFinished())
	return (NULL);
    }
}

void			*consumer(void *)
{
  int			i;

  while (42)
    {
      if (!test.tryPop(&i))
	{
	  std::cout << "false" << std::endl;
	  usleep(rand() % 100000);
	}
      else
	std::cout << i << std::endl;
      if (test.isFinished())
	return (NULL);
    }
}

void			stop(int)
{
  std::cout << "Killed by signal" << std::endl;
  test.setFinished();
}

int			main(int ac, char **av)
{
  Thread		*Consumers;
  Thread		*Producers;
  int			nbConsumer;
  int			nbProducer;
  int			i;

  if (ac < 2)
    return (-1);
  signal(SIGINT, &stop);
  nbConsumer = atoi(av[1]);
  nbProducer = atoi(av[2]);
  Consumers = new Thread[nbConsumer];
  Producers= new Thread[nbProducer];
  for (i = 0; i < nbConsumer; i++)
    Consumers[i].start(&consumer, NULL);
  for (i = 0; i < nbProducer; i++)
    Producers[i].start(&producer, NULL);
  for (i = 0; i < nbConsumer; i++)
    Consumers[i].join();
  for (i = 0; i < nbProducer; i++)
    Producers[i].join();
  delete[] Consumers;
  delete[] Producers;
}
