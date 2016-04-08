//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 09:54:16 2016 Nyrandone Noboud-Inpeng
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
  t_processState	mdr;

  // core();
  tmp->create(0);
  mdr.id = 42;
  mdr.tmp = "mdr";
  std::cout << mdr.id << std::endl;
  std::cout << mdr.tmp << std::endl;
  if (!(pid = fork()))
    {
      tmp->write2(mdr);
      // std::string("OKEEEEEEEE") >> *tmp;
      exit(0);
    }
  mdr.id = 2;
  mdr.tmp = "lol";
  tmp->read2(mdr);
  std::cout << mdr.id << std::endl;
  std::cout << mdr.tmp << std::endl;

  delete tmp;
  return (0);
}
