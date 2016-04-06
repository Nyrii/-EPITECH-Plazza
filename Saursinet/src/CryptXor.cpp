//
// CryptXor.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:18:46 2016 Florian Saurs
// Last update Thu Apr  7 00:22:30 2016 Florian Saurs
//

#include "../inc/CryptXor.hpp"

CryptXor::CryptXor()
{}

CryptXor::~CryptXor()
{}

std::string	CryptXor::decrypt(int key, std::string msg)
{
  int		pos;

  pos = 0;
  while (msg[pos])
    {
      msg[pos] = msg[pos] ^ key;
      ++pos;
    }
  return (msg);
}
