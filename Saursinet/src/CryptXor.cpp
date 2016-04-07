//
// CryptXor.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:18:46 2016 Florian Saurs
// Last update Thu Apr  7 17:34:00 2016 Florian Saurs
//

#include "../inc/CryptXor.hpp"

CryptXor::CryptXor()
{}

CryptXor::~CryptXor()
{}

std::string	CryptXor::decrypt(uint16_t key, std::string msg)
{
  int		pos;
  char		keyFirst;

  pos = 0;
  while (msg[pos])
    {
      keyFirst = key >> 8;
      msg[pos] = msg[pos] ^ keyFirst;
      ++pos;
      if (msg[pos])
	{
	  msg[pos] = msg[pos] ^ key;
	  ++pos;
	}
    }
  return (msg);
}
