//
// Process.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 16:31:06 2016 guillaume wilmot
// Last update Fri Apr 15 22:02:06 2016 Florian Saurs
//

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Process.hpp"

Process::Process(ICommunication *com)
{
  _pid = 0;
  _com = com;
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

bool			Process::checkAvailable()
{
  t_processState	state;

  state.id = 0;
  state.free = 0;
  state.info = PHONE_NUMBER;
  state.fileName = "";
  state.state = FREE;
  _com->write(state);
  _com->read(state);
  return (state.free);
}

void			Process::assign(const std::string &fileName, Information info)
{
  t_processState	state;

  state.id = 0;
  state.free = 0;
  state.info = info;
  state.fileName = fileName;
  state.state = ASSIGN;
  _com->write(state);
}
