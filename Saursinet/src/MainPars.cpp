//
// MainPars.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:23:53 2016 Florian Saurs
// Last update Tue Apr  5 02:15:33 2016 Florian Saurs
//

#include "../inc/Parsing.hpp"

int	main(int ac, char **av)
{
  Parsing	pars;
  int		i;

  i = 0;
  if (ac == 1)
    std::cout << "I want the file to parse in parameter" << std::endl;
  else
    while (av[i])
      pars.parseFile(av[i++]);
  return (0);
}
