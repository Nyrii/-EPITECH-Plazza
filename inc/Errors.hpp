//
// Errors.hpp for Errors in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr  8 10:56:46 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 18:36:15 2016 Nyrandone Noboud-Inpeng
//

#ifndef ERRORS_HPP_
# define ERRORS_HPP_

# include <iostream>
# include <stdexcept>

class			Error : public std::exception
{
public:
  Error() {};
  ~Error() {};
  virtual char const	*what() const throw();
protected:
  std::string		_message;
};

class			CommunicationError : public Error
{
public:
  CommunicationError(std::string const &message = "An error occured.");
  virtual		~CommunicationError() throw();
};

#endif /* ERRORS_HPP_ */
