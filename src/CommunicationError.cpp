//
// CommunicationError.cpp for CommunicationError in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr  8 17:59:48 2016 Nyrandone Noboud-Inpeng
// Last update Wed Apr 13 15:26:42 2016 Nyrandone Noboud-Inpeng
//

#include "Errors.hpp"

CommunicationError::CommunicationError(std::string const &message)
{
  _message = message;
}

CommunicationError::~CommunicationError() throw()
{

}
