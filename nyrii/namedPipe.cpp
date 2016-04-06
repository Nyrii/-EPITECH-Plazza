//
// Pipe.cpp for Pipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 22:15:29 2016 Nyrandone Noboud-Inpeng
// Last update Wed Apr  6 15:26:04 2016 Nyrandone Noboud-Inpeng
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
  unlink((std::string("./") + std::to_string(_id)).c_str());
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
  if (mkfifo((std::string("./") + std::to_string(_id)).c_str(),
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

int				namedPipe::destroy()
{
  if (unlink((static_cast<std::string>("./") + std::to_string(_id)).c_str()) == -1)
    {
      std::cerr << "Error: unlink of a named pipe failed." << std::endl;
      return (-1);
    }
  return (0);
}

std::string			namedPipe::read()
{
  std::ifstream			readFile(std::string("./") + std::to_string(_id), std::ifstream::in);
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

int				namedPipe::write(std::string const &command)
{
  // int				fd;
  //
  // if ((fd = open((std::string("./") + std::to_string(_id)).c_str(), O_WRONLY)) == -1)
  //   {
  //     std::cout << "mdr" << std::endl;
  //     std::cerr << "Error: opening of a named pipe failed." << std::endl;
  //     return (-1);
  //   }
  // ::write(fd, command.c_str(), command.length());
  // if (close(fd) == -1)
  //   {
  //     std::cerr << "Error: close of a named pipe failed." << std::endl;
  //     return (-1);
  //   }
  std::ofstream			writeFile(std::string("./") + std::to_string(_id), std::ifstream::out);

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