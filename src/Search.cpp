//
// Search.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:23 2016 Florian Saurs
// Last update Thu Apr 21 16:49:32 2016 guillaume wilmot
//

#include "Search.hpp"
#include "Regex.hpp"

/*
** _regs[1] = std::string("[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]{2,}\\.[a-zA-Z]{2,63}");
** true regex for mail
*/

// _regs[1] = std::string("[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+");

Search::Search()
{
  _regs = new std::string[3];
  _regs[0] = std::string("0[1-9]([ ]?[0-9]{2}){4}");
  _regs[1] = std::string("[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]{2,}\\.[a-zA-Z]{2,63}");
  _regs[2] = std::string("(([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])");
  _nbReg = 3;
}

Search::~Search()
{}

std::string	Search::searchInCurrent(std::string current, Information type) const
{
  Regex		*reg = new Regex ();

  return (reg->match(_regs[type], current));
}

std::vector<std::string>	Search::parseFile(std::string content, Information type) const
{
  std::string			result("");
  std::string			current;
  std::vector<std::string>	found;

  while (content != "")
    {
      result = searchInCurrent(content, type);
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
