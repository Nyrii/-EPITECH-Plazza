//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 11:00:18 2016 Nyrandone Noboud-Inpeng
//

#include <iostream>
#include <unistd.h>
#include <list>
#include <fstream>
#include "namedPipe.hh"
#include "CryptCaesar.hh"

int		main()
{
  CryptCaesar	tmp;

  std::cout << tmp.Decrypt("Vk av k'vewfetrzj dfe gfzex urej cv tlc tr wvirzk hlfz ?", 17) << std::endl;
   // namedPipe	*tmp = new namedPipe;
  // pid_t		pid;
  //
  // core();
  // tmp->create(0);
  // if (!(pid = fork()))
  //   {
  //     std::cout << pid << std::endl;
  //     std::string("OKEEEEEEEE") >> *tmp;
  //     exit(0);
  //   }
  // std::cout << *tmp;
  // delete tmp;
  return (0);
}
