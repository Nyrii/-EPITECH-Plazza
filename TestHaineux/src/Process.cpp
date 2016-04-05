//
// Process.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 16:31:06 2016 guillaume wilmot
// Last update Tue Apr  5 19:39:10 2016 guillaume wilmot
//

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Process.hpp"

Process::Process()
{
  _pid = 0;
}

std::string	Process::start()
{
  std::cout << "Process " << _id << " created" << std::endl;
  return ("");
}

int		Process::create(int id, int nbThread)
{
  std::string	str;

  (void)nbThread;
  _id = id;
  if ((_pid = fork()) == 0)
    {
      if ((str = start()) != "")
	std::cout << "lol";
      //send result in pipe
      exit(0);
    }
  return (_pid == -1 ? -1 : 0);
}
