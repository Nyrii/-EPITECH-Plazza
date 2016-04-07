//
// Pipe.cpp for Pipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 22:15:29 2016 Nyrandone Noboud-Inpeng
// Last update Wed Apr  6 22:52:53 2016 Nyrandone Noboud-Inpeng
//

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include "namedPipe.hh"

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
}

namedPipe			&namedPipe::operator=(namedPipe const &src)
{
  if (this != &src)
    {
      _id = src.getId();
    }
  return (*this);
}

int				namedPipe::create(int id)
{
  _id = id;
  if (mkfifo((std::string("./np") + std::to_string(_id)).c_str(),
	     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    {
      unlink((std::string("./") + std::to_string(_id)).c_str());
      if (mkfifo((std::string("./") + std::to_string(_id)).c_str(),
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
  if (unlink((static_cast<std::string>("./np") + std::to_string(_id)).c_str()) == -1)
    {
      std::cerr << "Error: unlink of a named pipe failed." << std::endl;
      return (-1);
    }
  return (0);
}

std::string			namedPipe::read() const
{
  std::ifstream			readFile(std::string("./np") + std::to_string(_id), std::ifstream::in);
  std::string			command = "";

  if (!readFile.is_open())
    {
      std::cerr << "Error: opening of a named pipe failed." << std::endl;
      return ("");
    }
  std::getline(readFile, command);
  readFile.close();
  return (command);
}

int				namedPipe::write(std::string const &command) const
{
  std::ofstream			writeFile(std::string("./np") + std::to_string(_id), std::ifstream::out);

  if (!writeFile.is_open())
    {
      std::cerr << "Error: opening of a named pipe failed." << std::endl;
      return (-1);
    }
  writeFile << command;
  writeFile.close();
  return (0);
}

int				namedPipe::getId() const
{
  return (_id);
}

std::ostream			&operator<<(std::ostream &os, namedPipe const &namedPipe)
{
  std::cout << namedPipe.read() << std::endl;
  return (os);
}

std::string const		&operator>>(std::string const &command, namedPipe const &namedPipe)
{
  namedPipe.write(command);
  return (command);
}
