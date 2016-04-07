//
// CryptCaesar.cpp for CryptCaesar in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:34:02 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 15:57:22 2016 Nyrandone Noboud-Inpeng
//

#include <iostream>
#include "CryptCaesar.hh"

CryptCaesar::CryptCaesar()
{

}

CryptCaesar::~CryptCaesar()
{

}

std::string		CryptCaesar::Decrypt(std::string to_decrypt, int key)
{
  for (unsigned int i = 0; i < to_decrypt.length(); i++)
    {
      if (isalpha(to_decrypt[i]))
	{
	  for (int k = 0; k < key; k++)
	    {
	      to_decrypt[i] -= 1;
	      if (!isalpha(to_decrypt[i]))
		to_decrypt[i] += ('z' - 'a') + 1;
	    }
	}
    }
  return (to_decrypt);
}
