//
// CryptCaesar.cpp for CryptCaesar in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:34:02 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 11:08:46 2016 Nyrandone Noboud-Inpeng
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
  char		save;
  int		i = 0;

  while (to_decrypt[i])
    {
      if ((to_decrypt[i] >= 'A' && to_decrypt[i] <= 'Z')
	  || (to_decrypt[i] >= 'a' && to_decrypt[i] <= 'z'))
	{
	  save = to_decrypt[i];
	  for (int k = 0; k < key; k++)
	    {
	      to_decrypt[i] -= 1;
	      if ((to_decrypt[i] < 'a' && save >= 'a' && save <= 'z')
		  || (to_decrypt[i] < 'A' && save >= 'A' && save <= 'Z'))
		to_decrypt[i] += ('z' - 'a') + 1;
	    }
	}
      ++i;
    }
  return (to_decrypt);
}
