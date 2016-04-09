//
// Errors.cpp for Errors in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr  8 18:02:19 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 18:02:38 2016 Nyrandone Noboud-Inpeng
//

#include "Errors.hpp"

char const	*Error::what() const throw()
{
  return (_message.c_str());
}
