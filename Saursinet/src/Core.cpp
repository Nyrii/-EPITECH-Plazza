//
// Core.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:58:09 2016 Florian Saurs
// Last update Tue Apr  5 18:33:13 2016 Florian Saurs
//

#include <boost/regex.hpp>
#include "../inc/Core.hpp"

Core::Core()
{
  _comparison.push_back("PHONE_NUMBER");
  _comparison.push_back("EMAIL_ADDRESS");
  _comparison.push_back("IP_ADDRESS");
}

Core::~Core()
{}

int				Core::commandIsFalse(std::string str) const
{
  boost::smatch	matches;
  boost::regex	reg("[0-9a-zA-Z._-]+[ ]{1,}(PHONE_NUMBER|EMAIL_ADDRESS|IP_ADDRESS)");

  if (boost::regex_search(str, matches, reg))
    return (0);
  return (1);
}

int				Core::read() const
{
  std::string			input("");
  std::vector<std::string>	*command;
  int				i;

  getline(std::cin, input);
  while (input != "")
    {
      command = new std::vector<std::string>(0, "");
      while (input.find(";") != std::string::npos)
	{
	  i = 1;
	  command->push_back(input.substr(0, input.find(";")));
	  while (input.c_str()[i + input.find(";")] == ' ' ||
		 input.c_str()[i + input.find(";")] == '\t')
	    ++i;
	  input = input.substr(input.find(";") + i);
	}
      command->push_back(input.substr(0, input.find(";")));
      for (std::vector<std::string>::iterator it = command->begin();
	   it != command->end(); ++it)
	{
	  if (*it == "" || (i = commandIsFalse(*it)) == 1)
	    {
	      if (i == 1)
		std::cerr << "Wrong argument in line command." << std::endl;
	      it = command->erase(it);
	      --it;
	    }
	}
      parseCommandLine(command);
      delete(command);
      getline(std::cin, input);
    }
  return (0);
}

int		Core::parseCommandLine(std::vector<std::string> *command) const
{
  for (std::vector<std::string>::iterator it = command->begin();
       it != command->end(); ++it)
    std::cout << *it << std::endl;
  return (0);
}
