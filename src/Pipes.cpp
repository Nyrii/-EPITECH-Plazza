//
// Pipes.cpp for Pipes in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 10:46:45 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 18:30:34 2016 Nyrandone Noboud-Inpeng
//

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
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
  _out = new PipeOut();
  _in = new PipeIn();
  _out->setReadFd(open(_path.c_str(), O_RDONLY | O_NONBLOCK));
  if (_out->getReadFd() == -1)
    throw CommunicationError("Error: opening of a named pipe to read in it failed.");
  _in->setWriteFd(open(_path.c_str(), O_WRONLY | O_NONBLOCK));
  if (_in->getWriteFd() == -1)
    throw CommunicationError("Error: opening of a named pipe to write in it failed.");
}

Pipes::~Pipes()
{
  delete _out;
  delete _in;
  if (unlink(_path.c_str()) == -1)
    throw CommunicationError("Error: unlink of a named pipe failed.");
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
  if (unlink(_path.c_str()) == -1)
    throw CommunicationError("Error: unlink of a named pipe failed.");
  return (0);
}
