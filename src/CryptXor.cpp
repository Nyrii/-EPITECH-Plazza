//
// CryptXor.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:18:46 2016 Florian Saurs
// Last update Sun Apr 17 16:18:05 2016 guillaume wilmot
//

#include "CryptXor.hpp"

CryptXor::CryptXor()
{}

CryptXor::~CryptXor()
{}

std::string	CryptXor::Decrypt(std::string msg, int, uint16_t key)
{
  int		pos;
  char		keyFirst;

  pos = 0;
  keyFirst = key >> 8;
  while (msg[pos])
    {
      if (pos % 2)
	msg[pos] = msg[pos] ^ key;
      else
	msg[pos] = msg[pos] ^ keyFirst;
      pos++;
    }
  return (msg);
}
