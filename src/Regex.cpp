//
// Regex.cpp for plazza in /home/saurs_f/cpp_plazza/src/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Tue Apr 19 12:00:38 2016 Florian Saurs
// Last update Mon Apr 18 08:57:14 2016 Nyrandone Noboud-Inpeng
//

#include <regex.h>
#include <cstring>
#include "Regex.hpp"
#include "RegexError.hh"

Regex::Regex()
{}

Regex::~Regex()
{}

std::string	Regex::match(std::string regex, std::string str)
{
  regex_t	preg;
  int		match;
  size_t	nmatch = 0;
  regmatch_t	*pmatch;

  if (regcomp(&preg, regex.c_str(), REG_EXTENDED) == -1)
    throw RegexError("Invalid regex");
  nmatch = 1;
  pmatch = new regmatch_t[nmatch];

  match = regexec(&preg, str.c_str(), nmatch, pmatch, 0);
  regfree(&preg);

  if (match == 0)
    {
      char		*result;
      size_t		size;

      size = pmatch[0].rm_eo - pmatch[0].rm_so;
      if (size == 0)
	return ("");
      result = new char[size + 1];

      strncpy(result, &str.c_str()[pmatch[0].rm_so], size);
      result[size] = 0;
      return (result);
      delete [] result;
    }
  return ("");
}
