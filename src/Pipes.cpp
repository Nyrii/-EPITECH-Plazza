//
// Pipes.cpp for Pipes in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 10:46:45 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 12:46:51 2016 Nyrandone Noboud-Inpeng
//

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "Pipes.hpp"
#include "Errors.hpp"

PipeOut::PipeOut(PipeOut const &src)
{
  _readFd = src.getReadFd();
}

PipeOut		&PipeOut::operator=(PipeOut const &src)
{
  if (this != &src)
    {
      _readFd = src.getReadFd();
    }
  return (*this);
}

void		PipeOut::destroy() const
{
  close(_readFd);
}

int		PipeOut::write(t_processState &) const
{
  return (-1);
}

int		PipeOut::read(t_processState &state) const
{
  if (::read(_readFd, &state, sizeof(t_processState)) == -1)
    return (-1);
  return (0);
}

int		PipeOut::getReadFd() const
{
  return (_readFd);
}

void		PipeOut::setReadFd(int const &newFd)
{
  _readFd = newFd;
}






PipeIn::PipeIn(PipeIn const &src)
{
  _writeFd = src.getWriteFd();
}

PipeIn		&PipeIn::operator=(PipeIn const &src)
{
  if (this != &src)
    {
      _writeFd = src.getWriteFd();
    }
  return (*this);
}

void		PipeIn::destroy() const
{
  close(_writeFd);
}

int		PipeIn::write(t_processState &state) const
{
  if (::write(_writeFd, &state, sizeof(t_processState)) == -1)
    return (-1);
  return (0);
}

int		PipeIn::read(t_processState &) const
{
  return (-1);
}

int		PipeIn::getWriteFd() const
{
  return (_writeFd);
}

void		PipeIn::setWriteFd(int const &newFd)
{
  _writeFd = newFd;
}





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
  _out.setReadFd(open(_path.c_str(), O_RDONLY | O_NONBLOCK));
  if (_out.getReadFd() == -1)
    throw CommunicationError("Error: opening of a named pipe to read in it failed.");
  _in.setWriteFd(open(_path.c_str(), O_WRONLY | O_NONBLOCK));
  if (_in.getWriteFd() == -1)
    throw CommunicationError("Error: opening of a named pipe to write in it failed.");
}

Pipes::~Pipes()
{
  _out.destroy();
  _in.destroy();
  if (unlink(_path.c_str()) == -1)
    throw CommunicationError("Error: unlink of a named pipe failed.");
}

int		Pipes::write(t_processState &state) const
{
  return (_in.write(state));
}

int		Pipes::read(t_processState &state) const
{
  return (_out.read(state));
}

int		Pipes::destroy() const
{
  _out.destroy();
  _in.destroy();
  if (unlink(_path.c_str()) == -1)
    throw CommunicationError("Error: unlink of a named pipe failed.");
  return (0);
}
