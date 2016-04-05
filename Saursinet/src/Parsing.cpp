//
// Parsing.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:23 2016 Florian Saurs
// Last update Tue Apr  5 15:05:29 2016 Florian Saurs
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include <dirent.h>
#include "../inc/Parsing.hpp"

Parsing::Parsing()
{
  _reg = new boost::regex[3];
  _reg[0] = boost::regex("0[1-68]([ ]?[0-9]{2}){4}");
  _reg[1] = boost::regex("[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]{2,}\\.[a-z]{2,4}");
  _reg[2] = boost::regex("([0-9]{1,3}\\.){3}[0-9]{1,3}");
  _nbReg = 3;
}

Parsing::~Parsing()
{}

std::string	Parsing::searchInCurrent(std::string current) const
{
  boost::smatch	matches;

  for (int i = 0; i < _nbReg; ++i)
    if (boost::regex_search(current, matches, _reg[i]))
      return (matches[0]);
  return ("");
}

void		Parsing::parseFile(std::string name) const
{
  std::string	result("");
  std::string	current("");
  std::string	tmp("");
  std::vector<std::string>	found;
  DIR		*directory;

  directory = opendir(name.c_str());
  if (directory != NULL)
    {
      closedir(directory);
      std::cerr << name << " is a directory." << std::endl;
      return ;
    }
  std::ifstream	file(name.c_str(), std::ifstream::in);

  std::string content( (std::istreambuf_iterator<char>(file) ),
                       (std::istreambuf_iterator<char>()    ) );

  while (content != "")
    {
      result = searchInCurrent(content);
      if (result != "")
	{
	  found.push_back(result);
	  if (content.find(result) == std::string::npos + result.length())
	    content = "";
	  else
	    content = content.substr(content.find(result) + result.length());
	}
      else
	content = "";
    }
  if (found.size() != 0)
    for (unsigned int i = 0; i < found.size(); ++i)
      std::cout << found.at(i) << std::endl;
  else
    std::cout << "Not found" << std::endl;
  file.close();
}
