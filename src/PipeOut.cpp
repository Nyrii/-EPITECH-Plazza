//
// PipeOut.cpp for PipeOut in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:05:28 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 18:26:02 2016 Nyrandone Noboud-Inpeng
//

#include <unistd.h>
#include "PipeOut.hh"

PipeOut::PipeOut()
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

int		PipeOut::getWriteFd() const
{
  return (-1);
}

void		PipeOut::setWriteFd(int const &)
{

}
