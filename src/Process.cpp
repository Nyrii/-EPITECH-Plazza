//
// Process.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 16:31:06 2016 guillaume wilmot
// Last update Fri Apr 15 23:49:21 2016 Florian Saurs
//

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
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
  t_processState	*state;

  state = new t_processState;
  memset(state, 0, sizeof(*state));
  state->id = 0;
  state->free = 0;
  state->info = PHONE_NUMBER;
  memset(state->fileName, 0, sizeof(state->fileName));
  state->state = FREE;
  _com->write(*state);
  _com->read(*state);
  return (state->free);
}

void			Process::assign(const std::string &fileName, Information info)
{
  t_processState	*state;

  std::cout << "the filename is " << fileName << " and info is " << info << std::endl;

  state = new t_processState;
  memset(state, 0, sizeof(*state));
  state->id = 20;
  state->free = 0;
  state->info = info;
  memset(state->fileName, 0, sizeof(state->fileName));
  std::strncpy(state->fileName, fileName.c_str(), std::strlen(fileName.c_str()));
  state->state = ASSIGN;
  _com->write(*state);
}
