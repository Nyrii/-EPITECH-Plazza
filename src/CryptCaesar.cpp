//
// CryptCaesar.cpp for CryptCaesar in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:34:02 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr  9 19:27:49 2016 Nyrandone Noboud-Inpeng
//

#include "CryptCaesar.hh"

CryptCaesar::CryptCaesar()
{

}

CryptCaesar::~CryptCaesar()
{

}

std::string		CryptCaesar::Decrypt(std::string to_decrypt, int key, uint16_t)
{
  for (unsigned int i = 0; i < to_decrypt.length(); i++)
    {
      if (to_decrypt[i] - key < 0)
	to_decrypt[i] = (to_decrypt[i] - key + 255) % 255;
      else
	to_decrypt[i] = (to_decrypt[i] - key) % 255;
    }
  return (to_decrypt);
}
