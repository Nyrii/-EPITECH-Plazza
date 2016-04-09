//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 22:48:21 2016 guillaume wilmot
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
      std::string("OKEEEEEEEEPDSUCEMESBOULE") >> *tmp;
      exit(0);
    }

  int		str[6];
  for (int i = 0; i < 6; i++)
    str[i] = 0;
  tmp->read2(str);
  for (int i = 0; i < 6; i++)
    std::cout << str[i] << " ";

  delete tmp;
  return (0);
}
