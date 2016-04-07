//
// Process.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 16:31:06 2016 guillaume wilmot
// Last update Thu Apr  7 00:19:03 2016 guillaume wilmot
//

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Process.hpp"

Process::Process()
{
  _pid = 0;
}

int		Process::create(void *(*ptr)(void *), void *arg)
{
  void		*ret;

  if ((_pid = fork()) == 0)
    {
      ret = ptr(arg);
      exit(ret == NULL ? -1 : 0);
    }
  return (_pid == -1 ? -1 : 0);
}
