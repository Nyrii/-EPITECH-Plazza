//
// CryptXor.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:19:09 2016 Florian Saurs
// Last update Fri Apr  8 10:43:39 2016 Florian Saurs
//

#ifndef CRYPTXOR
# define CRYPTXOR

# include "ICrypt.hpp"

class	CryptXor : public ICrypt
{
public:
  CryptXor();
  ~CryptXor();

  std::string	Decrypt(std::string, int, uint16_t);
};

#endif /* !CRYPTXOR */
