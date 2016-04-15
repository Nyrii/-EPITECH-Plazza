//
// main.cpp for main.cpp in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:17:23 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 18:32:15 2016 Nyrandone Noboud-Inpeng
//

#include <iostream>
#include <unistd.h>
#include <list>
#include <fstream>
#include "Core.hpp"
#include "CryptCaesar.hh"
#include "Error.hpp"

int		main(int ac, char **av)
{
  int	nbThreads;

  nbThreads = 2;
  if (ac == 2)
    try {
      nbThreads = std::stoi(av[1]);
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << ": invalid argument, positive number expected."<< std::endl;
      return (-1);
    }
  if (nbThreads <= 0)
    {
      std::cerr << "Usage: ./plazza [nbr of threads]" << std::endl << "Positive non-NULL number expected." << std::endl;
      return (-1);
    }
  Core	*core = new Core(nbThreads);

    try {
      core->read();
    } catch (Error &e) {
      std::cerr << e.what() << std::endl;
    }
  delete core;
  return (0);
}

//Saurs le sorcier de la norme
