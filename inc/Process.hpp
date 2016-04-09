//
// Process.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:05 2016 guillaume wilmot
// Last update Thu Apr  7 00:11:35 2016 guillaume wilmot
//

#ifndef PROCESS_HP_
# define PROCESS_HPP_

class		Process {
private:
  int		_pid;

public:
  Process();
  ~Process() {}

  int			create(void *(*)(void *), void *);
};

#endif /* !PROCESS_HPP_ */
