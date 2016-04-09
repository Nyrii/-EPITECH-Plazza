//
// Main.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:36 2016 guillaume wilmot
// Last update Fri Apr  8 17:19:18 2016 guillaume wilmot
//

/**/
#include <unistd.h>
/**/
#include <iostream>
#include <cstdlib>
#include "Process.hpp"
#include "Listener.hpp"

int			main(int ac, char **av)
{
  Process		*process;
  int			nbProcess;
  int			args[2];

  if (ac < 2)
    {
      std::cerr << "usage" << std::endl;
      return (-1);
    }
  nbProcess = std::atoi(av[1]);
  args[0] = nbProcess;
  process = new Process[nbProcess];
  // for (int i = 0; i < nbProcess; i++)
  for (int i = 0; i < 1; i++)
    {
      args[1] = i;
      process[i].create(&Listener::start, args);
    }
  while (1) sleep(1);
  return (0);
}
