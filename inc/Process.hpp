//
// Process.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:05 2016 guillaume wilmot
// Last update Tue Apr 12 14:21:44 2016 Nyrandone Noboud-Inpeng
//

#ifndef PROCESS_HPP_
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
