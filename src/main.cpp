//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 20:45:14 2016 guillaume wilmot
//

#include <iostream>
#include <unistd.h>
#include <list>
#include <fstream>
#include "namedPipe.hpp"
#include "CryptCaesar.hh"

int		main()
{
  // CryptCaesar	tmp;
  // std::cout << tmp.Decrypt("Xlzccrldv Nzcdfk kvb2 wfivmvi", 17) << std::endl;

  namedPipe	*tmp = new namedPipe;
  pid_t		pid;

  // core();
  tmp->create(0);
  if (!(pid = fork()))
    {
      std::cout << pid << std::endl;
      std::string("OKEEEEEEEE") >> *tmp;
      exit(0);
    }

  char 	str[100];
  tmp->read2(str);
  std::cout << str;

  delete tmp;
  return (0);
}
