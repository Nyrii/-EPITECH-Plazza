//
// Core.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:57:11 2016 Florian Saurs
// Last update Sat Apr 16 01:37:09 2016 guillaume wilmot
//

#ifndef CORE_HPP_
# define CORE_HPP_

# include <vector>
# include <iostream>
# include "ICommunication.hpp"
# include "Process.hpp"
# include "Queue.hpp"

enum	Communication {
  LOCAL_SOCKET,
  INTERNET_SOCKET,
  NAMED_PIPE
};

class	Core
{
  std::vector<Process *>	_sonTab;
  bool				_isFinished;
  int				_nbThreads;

public:
  Core(int);
  ~Core();

  void	runProcessNP(std::string, Information, Communication);
  void	runProcessSocket(std::string, Information, Communication);
  // void	execParse(std::string, Information) const;
  int	checkAvailable() const;
  // void	launchWorkNP(std::string, NamedPipe *, Information);
  void	launchWorkSocket(std::string, Information, int);
  void	read() const;
};

#endif /* !CORE_HPP_ */
