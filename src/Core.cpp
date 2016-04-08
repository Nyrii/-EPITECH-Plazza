//
// Core.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:58:09 2016 Florian Saurs
// Last update Fri Apr  8 23:53:31 2016 Florian Saurs
//

#include <dirent.h>
#include <boost/regex.hpp>
#include <fstream>
#include <stdint.h>
#include "../inc/Core.hpp"
#include "../inc/Parsing.hpp"
#include "../inc/CryptXor.hpp"
#include "../inc/CryptCaesar.hh"

Core::Core()
{
  _compare.insert(std::pair<std::string, type>("PHONE_NUMBER", PHONE_NUMBER));
  _compare.insert(std::pair<std::string, type>("EMAIL_ADDRESS", EMAIL_ADDRESS));
  _compare.insert(std::pair<std::string, type>("IP_ADDRESS", IP_ADDRESS));
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

void		Core::takeCommandFromInput(std::string input, std::vector<std::string> *command) const
{
  int		i;

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
}

int				Core::read() const
{
  std::string			input("");
  std::vector<std::string>	*command;

  while (getline(std::cin, input))
    {
      command = new std::vector<std::string>(0, "");
      takeCommandFromInput(input, command);
      parseCommandLine(command);
      delete(command);
    }
  return (0);
}

void				Core::runProcess(std::string fileName, type _type) const
{
  Parsing			pars;
  std::vector<std::string>	found;
  uint16_t			i = 0;
  int				start = 0;
  CryptXor			Xor;
  std::ifstream			file(fileName.c_str(), std::ifstream::in);
  std::string			content((std::istreambuf_iterator<char>(file) ),
					(std::istreambuf_iterator<char>()    ) );


  found = pars.parseFile(content, _type);
  while (found.size() == 0)
    {
      while ((i != 0 || start == 0) && found.size() == 0)
	{
	  start = 1;
	  found = pars.parseFile(Xor.Decrypt(content, 0, i++), _type);
	}
      start = 0;
      while (start < 24 && found.size() == 0)
	found = pars.parseFile(Xor.Decrypt(content, start++, 0), _type);
    }
  for (std::vector<std::string>::iterator it = found.begin(); it != found.end(); ++it)
    std::cout << *it << std::endl;
  file.close();
}

int				Core::parseCommandLine(std::vector<std::string> *command) const
{
  DIR				*directory;
  std::vector<std::string>	*filesName;


  for (std::vector<std::string>::iterator it = command->begin();
       it != command->end(); ++it)
    {
      filesName = new std::vector<std::string>(0, "");
      while ((*it).find(" ") != std::string::npos)
	{
	  filesName->push_back((*it).substr(0, (*it).find(" ")));
	  *it = (*it).substr((*it).find(" ") + 1);
	}
      for (std::vector<std::string>::iterator itFiles = filesName->begin();
	   itFiles != filesName->end(); ++itFiles)
	{
	  if (access((*itFiles).c_str(), F_OK) == -1)
	    std::cerr << *itFiles << ": file doesn't exist." << std::endl;
	  else if (access((*itFiles).c_str(), R_OK) == -1)
	    std::cerr << *itFiles << ": file cannot be read." << std::endl;
	  else if ((directory = opendir((*itFiles).c_str())) != NULL)
	    {
	      std::cerr << *itFiles << ": is a directory." << std::endl;
	      closedir(directory);
	    }
	  else
	    runProcess(*itFiles, _compare.at(*it));
	}
      delete(filesName);
    }
  return (0);
}
