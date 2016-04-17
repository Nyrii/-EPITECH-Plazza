//
// Error.hpp for Error in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr  8 10:56:46 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr 17 21:53:42 2016 guillaume wilmot
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

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

#endif /* ERROR_HPP_ */
