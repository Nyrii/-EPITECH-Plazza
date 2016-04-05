//
// Core.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:57:11 2016 Florian Saurs
// Last update Tue Apr  5 18:02:43 2016 Florian Saurs
//

#ifndef CORE_HPP_
# define CORE_HPP_

# include <vector>
# include <iostream>

class	Core
{
  std::vector<std::string>	_comparison;

public:
  Core();
  ~Core();

  int	read() const;
  int	parseCommandLine(std::vector<std::string> *) const;
  int	commandIsFalse(std::string) const;
};

#endif /* !CORE_HPP_ */
