//
// Core.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:57:11 2016 Florian Saurs
// Last update Sat Apr  9 20:24:23 2016 Saursinet
//

#ifndef CORE_HPP_
# define CORE_HPP_

# include <map>
# include <vector>
# include <iostream>
# include "ICommunication.hpp"

enum	type {
  PHONE_NUMBER,
  EMAIL_ADDRESS,
  IP_ADDRESS
};

class	Core
{
  std::map<std::string, type>	_compare;
  std::map<int, ICommunication *>	_sonTab;

public:
  Core();
  ~Core();

  int	read() const;
  int	parseCommandLine(std::vector<std::string> *);
  int	commandIsFalse(std::string) const;
  void	takeCommandFromInput(std::string, std::vector<std::string> *) const;
  void	runProcess(std::string, type);
  void	execParse(std::string, type) const;
  void	initConnection(void *) const;
};

#endif /* !CORE_HPP_ */
