//
// Core.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:57:11 2016 Florian Saurs
// Last update Wed Apr 13 13:52:55 2016 Nyrandone Noboud-Inpeng
//

#ifndef CORE_HPP_
# define CORE_HPP_

# include <map>
# include <vector>
# include <iostream>
# include "ICommunication.hpp"
# include "NamedPipe.hh"

enum	type {
  PHONE_NUMBER,
  EMAIL_ADDRESS,
  IP_ADDRESS
};

enum	Communication {
  LOCAL_SOCKET,
  INTERNET_SOCKET,
  NAMED_PIPE
};

class	Core
{
  std::map<int, ICommunication *>	_sonTab;
  bool				_isFinished;
  int				_nbThreads;

public:
  Core(int);
  ~Core();

  void	runProcessNP(std::string, type, Communication);
  void	runProcessSocket(std::string, type, Communication);
  void	execParse(std::string, type) const;
  int	checkAvailable() const;
  void	fillIt(int, std::string);
  void	launchWork(std::string, NamedPipe *, type);
  void	read() const;
};

#endif /* !CORE_HPP_ */
