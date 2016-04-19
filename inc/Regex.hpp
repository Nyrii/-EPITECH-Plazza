//
// Regex.hpp for  in /home/saurs_f/cpp_plazza/inc/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Tue Apr 19 12:00:52 2016 Florian Saurs
// Last update Tue Apr 19 12:40:29 2016 Florian Saurs
//

#ifndef REGEX_HPP_
# define REGEX_HPP_

# include <iostream>

class	Regex
{
public:
  Regex();
  ~Regex();

  std::string	match(std::string, std::string);
};

#endif /* !REGEX_HPP_ */
