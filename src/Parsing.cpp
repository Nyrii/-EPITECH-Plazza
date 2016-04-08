//
// Parsing.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:23 2016 Florian Saurs
// Last update Fri Apr  8 23:50:51 2016 Florian Saurs
//

#include <iostream>
#include <fstream>
#include <cstdio>
#include "../inc/Parsing.hpp"

Parsing::Parsing()
{
  _reg = new boost::regex[3];
  _reg[0] = boost::regex("0[1-9]([ ]?[0-9]{2}){4}");
  _reg[1] = boost::regex("[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]{2,}\\.[a-z]{2,4}");
  _reg[2] = boost::regex("(([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])");
  _nbReg = 3;
}

Parsing::~Parsing()
{}

std::string	Parsing::searchInCurrent(std::string current, type _type) const
{
  boost::smatch	matches;

  if (boost::regex_search(current, matches, _reg[_type]))
    return (matches[0]);
  return ("");
}

std::vector<std::string>	Parsing::parseFile(std::string content, type _type) const
{
  std::string			result("");
  std::string			current;
  std::vector<std::string>	found;

  while (content != "")
    {
      result = searchInCurrent(content, _type);
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
  return (found);
}
