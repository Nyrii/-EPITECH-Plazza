//
// CryptXor.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:19:09 2016 Florian Saurs
// Last update Fri Apr  8 23:36:15 2016 Florian Saurs
//

#ifndef CRYPTXOR
# define CRYPTXOR

# include <stdint.h>
# include <iostream>

class	CryptXor
{
public:
  CryptXor();
  ~CryptXor();

  std::string	decrypt(uint16_t, std::string);
};

#endif /* !CRYPTXOR */
