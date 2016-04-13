//
// Pipe.cpp for Pipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 22:15:29 2016 Nyrandone Noboud-Inpeng
// Last update Wed Apr 13 13:50:10 2016 Nyrandone Noboud-Inpeng
//

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include "NamedPipe.hpp"
#include "Errors.hpp"

NamedPipe::NamedPipe()
{
  _id = 0;
  _rfd = 0;
  _wfd = 0;
}

NamedPipe::~NamedPipe()
{
  unlink(_path.c_str());
  close(_rfd);
  close(_wfd);
}

NamedPipe::NamedPipe(NamedPipe const &src)
{
  _id = src.getId();
  _path = src.getPath();
  _rfd = src.getReadFd();
  _wfd = src.getWriteFd();
}

NamedPipe			&NamedPipe::operator=(NamedPipe const &src)
{
  if (this != &src)
    {
      _id = src.getId();
      _path = src.getPath();
      _rfd = src.getReadFd();
      _wfd = src.getWriteFd();
    }
  return (*this);
}

int				NamedPipe::create(int id)
{
  _id = id;
  _path = std::string("./np") + std::to_string(_id);
  if (mkfifo(_path.c_str(),
	     S_IRWXU | S_IRGRP | S_IWGRP) == -1)
    {
      unlink(_path.c_str());
      if (mkfifo(_path.c_str(),
		 S_IRWXU | S_IRGRP | S_IWGRP) == -1)
	throw CommunicationError("Error: creation of a named pipe failed.");
    }
  std::cout << _path << std::endl;
  _rfd = open(_path.c_str(), O_RDONLY | O_NONBLOCK);
  if (_rfd == -1)
    {
      destroy();
      throw CommunicationError("Error: opening of a named pipe to read in it failed.");
    }
  _wfd = open(_path.c_str(), O_WRONLY | O_NONBLOCK);
  if (_wfd == -1)
    {
      destroy();
      throw CommunicationError("Error: opening of a named pipe to write in it failed.");
    }
  return (0);
}

int				NamedPipe::destroy() const
{
  if (unlink(_path.c_str()) == -1)
    {
      throw CommunicationError("Error: unlink of a named pipe failed.");
      return (-1);
    }
  close(_rfd);
  close(_wfd);
  return (0);
}

int				NamedPipe::write(t_processState &buf) const
{
  if (!::write(_wfd, &buf, sizeof(t_processState)))
    return (0);
  return (-1);
  // std::fstream			writeFile(_path, std::fstream::out);
  //
  // if (!writeFile.is_open())
  //   throw CommunicationError("Error: opening of a named pipe to write in it failed.");
  // writeFile.write(reinterpret_cast<char *>(&buf), sizeof(t_processState));
  // writeFile.close();
}

int				NamedPipe::read(t_processState &buf) const
{
  if (!::read(_rfd, &buf, sizeof(t_processState)))
    return (0);
  return (-1);
  // std::fstream			readFile(_path, std::fstream::in);
  //
  // if (!readFile.is_open())
  //   throw CommunicationError("Error: opening of a named pipe to read in it failed.");
  // readFile.read(reinterpret_cast<char *>(&buf), sizeof(t_processState));
  // readFile.close();
}

int				NamedPipe::getId() const
{
  return (_id);
}

std::string			NamedPipe::getPath() const
{
  return (_path);
}

int				NamedPipe::getReadFd() const
{
  return (_rfd);
}

int				NamedPipe::getWriteFd() const
{
  return (_wfd);
}
