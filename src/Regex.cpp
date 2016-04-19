//
// Regex.cpp for plazza in /home/saurs_f/cpp_plazza/src/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Tue Apr 19 12:00:38 2016 Florian Saurs
// Last update Tue Apr 19 15:47:24 2016 Florian Saurs
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
  regex_t	regStruc;
  int		match;
  regmatch_t	*found;

  if (regcomp(&regStruc, regex.c_str(), REG_EXTENDED) == -1)
    throw RegexError("Invalid regex");
  found = new regmatch_t;

  match = regexec(&regStruc, str.c_str(), 1, found, 0);
  regfree(&regStruc);

  if (match == 0)
    {
      char		*result;
      size_t		size;

      size = found[0].rm_eo - found[0].rm_so;
      if (size == 0)
	return ("");
      result = new char[size + 1];

      strncpy(result, &str.c_str()[found[0].rm_so], size);
      result[size] = 0;
      return (result);
      delete [] result;
    }
  return ("");
}
