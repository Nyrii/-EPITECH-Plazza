//
// PipeIn.cpp for PipeIn in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:13:08 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 18:23:50 2016 Nyrandone Noboud-Inpeng
//

#include <unistd.h>
#include "PipeIn.hh"

PipeIn::PipeIn()
{

}

PipeIn::~PipeIn()
{
  this->destroy();
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

int		PipeIn::getReadFd() const
{
  return (-1);
}

void		PipeIn::setReadFd(int const &)
{

}
