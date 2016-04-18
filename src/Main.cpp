//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 22:18:31 2016 Florian Saurs
//

#include <iostream>
#include <unistd.h>
#include <list>
#include <fstream>
#include <map>
#include "ParseAv.hpp"
#include "CryptCaesar.hh"
#include "Error.hpp"
#include "Thread.hpp"
#include "NoGUI.hpp"

int					main(int, char **av)
{
  ParseAv	*pars = new ParseAv(av);

  try {
    if (pars->pars() == -1)
      return (0);
  } catch (const Error &e) {
    std::cerr << e.what() << std::endl;
    return (-1);
  }
  Thread	Gui;
  Core		*core = new Core(pars->getNbThread());

  Gui.start(&launchGui, core);
  try {
    core->read(pars->getComWay());
  } catch (const Error &e) {
    std::cerr << e.what() << std::endl;
  }
  delete core;
  return (0);
}
