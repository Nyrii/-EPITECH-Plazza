//
// PipeOut.cpp for PipeOut in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:05:28 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr 16 18:25:25 2016 guillaume wilmot
//

#include <unistd.h>
#include <fcntl.h>
#include "PipeOut.hh"
#include "CommunicationError.hh"

PipeOut::PipeOut(std::string path) : _path(path)
{
}

PipeOut::~PipeOut()
{
  this->destroy();
}

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

int		PipeOut::write(t_processState &)
{
  return (-1);
}

int			PipeOut::read(t_processState &state)
{
  int			return_value;
  _readFd = (open(_path.c_str(), O_RDONLY));
  if (_readFd == -1)
    throw CommunicationError("Error: opening of a named pipe to read in it failed.");

  FD_ZERO(&_readSelect);
  FD_SET(_readFd, &_readSelect);
  return_value = select(_readFd + 1, &_readSelect, NULL, NULL, NULL);
  if (return_value > 0)
    if (FD_ISSET(_readFd, &_readSelect))
      return (::read(_readFd, &state, sizeof(t_processState)));
  return (return_value);
}

int		PipeOut::getReadFd() const
{
  return (_readFd);
}

void		PipeOut::setReadFd(int const &newFd)
{
  _readFd = newFd;
}

int		PipeOut::getWriteFd() const
{
  return (-1);
}

void		PipeOut::setWriteFd(int const &)
{

}
