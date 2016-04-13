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
# include "namedPipe.hpp"

enum	type {
  PHONE_NUMBER,
  EMAIL_ADDRESS,
  IP_ADDRESS
};

class	Core
{
  std::map<int, ICommunication *>	_sonTab;
  bool				_isFinished;
  int				_nbThreads;

public:
  Core(int);
  ~Core();

  void	runProcess(std::string, type);
  void	execParse(std::string, type) const;
  int	checkAvailable() const;
  void	fillIt(int, std::string);
  void	launchWork(std::string, NamedPipe *, type);
  void	read() const;
};

#endif /* !CORE_HPP_ */
