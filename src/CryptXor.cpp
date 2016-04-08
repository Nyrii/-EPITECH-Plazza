//
// CryptXor.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:18:46 2016 Florian Saurs
// Last update Fri Apr  8 17:23:03 2016 Nyrandone Noboud-Inpeng
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
