//
// Thread.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 16:01:55 2016 guillaume wilmot
// Last update Tue Apr  5 19:39:33 2016 guillaume wilmot
//

#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <cstdlib>
#include "Thread.hpp"
#include "Mutex.hpp"
#include "ScopedLock.hpp"
#include "SafeQueue.hpp"
#include "Process.hpp"

int			main(int ac, char **av)
{
  Process		*process;
  int			nbProcess;

  if (ac < 2)
    {
      std::cerr << "usage" << std::endl;
      return (-1);
    }
  nbProcess = std::atoi(av[1]);
  process = new Process[nbProcess];
  for (int i = 0; i < nbProcess; i++)
    process[i].create(i, 5);
  sleep(1);
  return (0);
}
