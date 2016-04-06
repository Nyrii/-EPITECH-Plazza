//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Wed Apr  6 15:25:26 2016 Nyrandone Noboud-Inpeng
//

#include <iostream>
#include <unistd.h>
#include "namedPipe.hh"

int		main()
{
  namedPipe	*tmp = new namedPipe;
  pid_t		pid;

  tmp->create(0);
  if (!(pid = fork()))
    {
      tmp->write(std::string("LOL"));
      exit(0);
    }
  tmp->read();
  delete tmp;
  return (0);
}
