//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 23:59:47 2016 Florian Saurs
//

// #include <iostream>
// #include <unistd.h>
// #include <list>
// #include <fstream>
#include "Core.hpp"
// #include "namedPipe.hpp"
// #include "CryptCaesar.hh"

#include <iostream>
#include <unistd.h>
#include <list>
#include <fstream>
#include "namedPipe.hpp"
#include "CryptCaesar.hh"
#include "Errors.hpp"

int		main()
{
  // CryptCaesar	tmp;
  // std::cout << tmp.Decrypt("Xlzccrldv Nzcdfk kvb2 wfivmvi", 17) << std::endl;

  // namedPipe	*tmp = new namedPipe;
  // pid_t		pid;
  // t_processState	mdr;

  // // core();
  // tmp->create(0);
  // mdr.id = 42;
  // mdr.fileName = "mdr";
  // std::cout << mdr.id << std::endl;
  // std::cout << mdr.fileName << std::endl;
  // if (!(pid = fork()))
  //   {
  //     tmp->write(mdr);
  //     // std::string("OKEEEEEEEE") >> *tmp;
  //     exit(0);
  //   }
  // mdr.id = 2;
  // mdr.fileName = "lol";
  // tmp->read(mdr);
  // std::cout << mdr.id << std::endl;
  // std::cout << mdr.fileName << std::endl;

  // delete tmp;
  Core	core;

  core.read();
  // core();
  // try
  //   {
  //     tmp->create(0);
  //     mdr.id = 42;
  //     mdr.fileName = "mdr";
  //     std::cout << mdr.id << std::endl;
  //     std::cout << mdr.fileName << std::endl;
  //     if (!(pid = fork()))
  // 	{
  // 	  tmp->write(mdr);
  // 	  // std::string("OKEEEEEEEE") >> *tmp;
  // 	  exit(0);
  // 	}
  //     mdr.id = 2;
  //     mdr.fileName = "lol";
  //     tmp->read(mdr);
  //     std::cout << mdr.id << std::endl;
  //     std::cout << mdr.fileName << std::endl;
  //   }
  // catch (Error &err)
  //   {
  //     std::cerr << err.what() << std::endl;
  //     return (-1);
  //   }
  // delete tmp;
  return (0);
}
