//
// Search.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:23 2016 Florian Saurs
// Last update Wed Apr 20 21:17:03 2016 Florian Saurs
//

#include "Search.hpp"
#include "Regex.hpp"

Search::Search()
{
  // _reg = new boost::regex[3];
  // _reg[0] = boost::regex("0[1-9]([ ]?[0-9]{2}){4}");
  // _reg[1] = boost::regex("[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]{2,}\\.[a-zA-Z]{2,63}");
  // _reg[2] = boost::regex("(([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])");
  _regs = new std::string[3];
  _regs[0] = std::string("0[1-9]([ ]?[0-9]{2}){4}");
  // _regs[1] = std::string("[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]{2,}\\.[a-zA-Z]{2,63}");
  _regs[1] = std::string("[a-zA-Z0-9._-]+@[a-zA-Z0-9._-]+");
  _regs[2] = std::string("(([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([1-9]?[0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])");
  _nbReg = 3;
}

Search::~Search()
{}

std::string	Search::searchInCurrent(std::string current, Information type) const
{
  Regex		*reg = new Regex ();

  return (reg->match(_regs[type], current));
  // boost::smatch	matches;
  // if (boost::regex_search(current, matches, _reg[type]))
  //   return (matches[0]);
  // return ("");
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
