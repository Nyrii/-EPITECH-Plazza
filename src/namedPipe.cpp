//
// Pipe.cpp for Pipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 22:15:29 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 10:47:28 2016 Nyrandone Noboud-Inpeng
//

#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include "namedPipe.hpp"

namedPipe::namedPipe()
{
  _id = 0;
}

namedPipe::~namedPipe()
{
  unlink((std::string("./np") + std::to_string(_id)).c_str());
}

namedPipe::namedPipe(namedPipe const &src)
{
  _id = src.getId();
  _path = src.getPath();
}

namedPipe			&namedPipe::operator=(namedPipe const &src)
{
  if (this != &src)
    {
      _id = src.getId();
      _path = src.getPath();
    }
  return (*this);
}

int				namedPipe::create(int id)
{
  _id = id;
  _path = std::string("./np") + std::to_string(_id);
  if (mkfifo(_path.c_str(),
	     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    {
      unlink(_path.c_str());
      if (mkfifo(_path.c_str(),
           S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
	{
	  std::cerr << "Error: creation of a named pipe failed." << std::endl;
	  return (-1);
	}
    }
  return (0);
}

int				namedPipe::destroy() const
{
  if (unlink(_path.c_str()) == -1)
    {
      std::cerr << "Error: unlink of a named pipe failed." << std::endl;
      return (-1);
    }
  return (0);
}

void				namedPipe::write(t_processState &buf) const
{
  std::fstream			writeFile(_path, std::fstream::out);

  if (!writeFile.is_open())
    {
      std::cerr << "Error: opening of a named pipe to write in it failed." << std::endl;
      return ;
    }
  writeFile.write(reinterpret_cast<char *>(&buf), sizeof(t_processState));
  writeFile.close();
}

void				namedPipe::read(t_processState &buf) const
{
  std::fstream			readFile(_path, std::fstream::in);

  if (!readFile.is_open())
    {
      std::cerr << "Error: opening of a named pipe to read in it failed." << std::endl;
      return ;
    }
  readFile.read(reinterpret_cast<char *>(&buf), sizeof(t_processState));
  readFile.close();
}

int				namedPipe::getId() const
{
  return (_id);
}

std::string			namedPipe::getPath() const
{
  return (_path);
}

std::ostream			&operator<<(std::ostream &os, namedPipe const &namedPipe)
{
  (void)namedPipe;
  // std::cout << namedPipe.read() << std::endl;
  return (os);
}

std::string const		&operator>>(std::string const &command, namedPipe const &namedPipe)
{
  (void)namedPipe;
  // namedPipe.write(command);
  return (command);
}
