//
// Pipe.cpp for Pipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 22:15:29 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr  5 23:32:54 2016 Nyrandone Noboud-Inpeng
//

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Pipe.hpp"


NamedPipe::NamedPipe()
{
  _id = 0;
}

NamedPipe::~NamedPipe()
{

}

NamedPipe::NamedPipe(NamedPipe const &src)
{
  _id = src.getId();
  _currentId = src.getCurrentId();
  _idList = src.getIdList();
  _namedPipe = src.getPipes();
}

NamedPipe			&NamedPipe::operator=(NamedPipe const &src)
{
  if (this != &src)
    {
      _id = src.getId();
      _currentId = src.getCurrentId();
      _idList = src.getIdList();
      _namedPipe = src.getPipes();
    }
  return (*this);
}

int				NamedPipe::create()
{
  if (mkfifo((static_cast<std::string>("./") + std::to_string(_id)).c_str(),
	     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1)
    {
      std::cerr << "Error: creation of a named pipe failed." << std::endl;
      return (-1);
    }
  _namedPipe[_id] = static_cast<std::string>("./") + std::to_string(_id);
  _idList.push_back(_id);
  _currentId = _id;
  _id += 1;
  return (0);
}

int				NamedPipe::destroy()
{
  if (unlink(_namedPipe[_currentId].c_str()) == -1)
    {
      std::cerr << "Error: unlink of a named pipe failed." << std::endl;
      return (-1);
    }
  return (0);
}

std::string			NamedPipe::read()
{
  std::ifstream			readFile(_namedPipe[_currentId], std::ifstream::in);
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

int				NamedPipe::write(std::string const &command)
{
  std::ofstream			writeFile(_namedPipe[_currentId], std::ifstream::out);

  if (!writeFile.is_open())
    {
      std::cerr << "Error: opening of a named pipe failed." << std::endl;
      return (-1);
    }
  writeFile << command;
  writeFile.close();
  return (0);
}

std::vector<int>		NamedPipe::getIdList() const
{
  return (_idList);
}

int				NamedPipe::getId() const
{
  return (_id);
}

int				NamedPipe::getCurrentId() const
{
  return (_currentId);
}

std::map<int, std::string>	NamedPipe::getPipes() const
{
  return (_namedPipe);
}

void				NamedPipe::setCurrentId(int id)
{
  _currentId = id;
}
