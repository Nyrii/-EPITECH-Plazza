//
// Parsing.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:23 2016 Florian Saurs
// Last update Tue Apr  5 11:12:01 2016 Nyrandone Noboud-Inpeng
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <dirent.h>
#include "../inc/Parsing.hpp"

Parsing::Parsing()
{
  _reg = new boost::regex[3];
  _reg[0] = boost::regex("0[1-9]([ ]?[0-9]{2}){4}");
  _reg[1] = boost::regex("[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]{2,}\\.[a-z]{2,4}");
  _reg[2] = boost::regex("([0-9]{1,3}\\.){4}");
  _nbReg = 3;
}

Parsing::~Parsing()
{}

std::string	Parsing::searchInCurrent(std::string current) const
{
  boost::smatch	matches;

  for (int i = 0; i < _nbReg; ++i)
    if (boost::regex_search(current, matches, _reg[i]))
      {
	std::string	match(matches[i].first, matches[i].second);
	return (match);
      }
  return ("");
}

void		Parsing::parseFile(std::string name) const
{
  std::string	result("");
  std::string	current;
  DIR		*directory;

  directory = opendir(name.c_str());
  if (directory != NULL)
    {
      std::cerr << name << " is a directory." << std::endl;
      return ;
    }
  closedir(directory);
  std::ifstream	file(name.c_str(), std::ifstream::in);

  if (file.is_open())
    {
      while (!file.eof() && result == "")
	{
	  std::getline(file, current);
	  result = searchInCurrent(current);
	}
    }
  if (result != "")
    std::cout << result << std::endl;
  else
    std::cout << "Not found" << std::endl;
  file.close();
}
