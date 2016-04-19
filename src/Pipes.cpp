//
// Pipes.cpp for Pipes in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 10:46:45 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 19 17:30:49 2016 Florian Saurs
//

#include <unistd.h>
#include <sys/stat.h>
#include "Pipes.hpp"
#include "PipeOut.hh"
#include "PipeIn.hh"
#include "CommunicationError.hh"

Pipes::Pipes(int id) : _id(id)
{
  _path = std::string("./np") + std::to_string(_id);
  if (mkfifo(_path.c_str(),
	     S_IRWXU | S_IRGRP | S_IWGRP) == -1)
    {
      unlink(_path.c_str());
      if (mkfifo(_path.c_str(),
		 S_IRWXU | S_IRGRP | S_IWGRP) == -1)
	throw CommunicationError("Error: creation of a named pipe failed.");
    }
  _out = new PipeOut(_path);
  _in = new PipeIn(_path);
}

Pipes::~Pipes()
{
  destroy();
}

int		Pipes::write(t_processState &state) const
{
  return (_in->write(state));
}

int		Pipes::read(t_processState &state) const
{
  return (_out->read(state));
}

int		Pipes::destroy() const
{
  delete _out;
  delete _in;
  unlink(_path.c_str());
  return (0);
}
