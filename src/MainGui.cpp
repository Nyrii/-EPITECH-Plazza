//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 15:47:29 2016 guillaume wilmot
//

#include <iostream>
#include <unistd.h>
#include <list>
#include <fstream>
#include "Core.hpp"
#include "CryptCaesar.hh"
#include "Error.hpp"
#include "Gui.hpp"

int		main(int ac, char **av)
{
  int		nbThreads;

  nbThreads = 2;
  if (ac == 2)
    try {
      nbThreads = std::stoi(av[1]);
    } catch (const std::invalid_argument &e) {
      std::cerr << e.what() << ": invalid argument, positive number expected." << std::endl;
      return (-1);
    }
  if (nbThreads <= 0)
    {
      std::cerr << "Usage: ./plazza [nbr of threads]" << std::endl << "Positive non-NULL number expected." << std::endl;
      return (-1);
    }

  Core		*core = new Core(nbThreads);
  Gui           gui;

  gui.init(core);
  gui.startMenu();
  delete core;
  return (0);
}
