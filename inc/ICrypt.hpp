//
// ICrypt.hpp for ICrypt in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:29:44 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 10:42:38 2016 Florian Saurs
//

#ifndef ICRYPT_HPP_
# define ICRYPT_HPP_

# include <iostream>
# include <stdint.h>

class			ICrypt
{
public:
  virtual		~ICrypt() {};
virtual std::string	Decrypt(std::string, int, uint16_t) = 0;
};

#endif /* !ICRYPT_HPP_ */
