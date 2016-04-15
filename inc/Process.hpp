//
// Process.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:05 2016 guillaume wilmot
// Last update Fri Apr 15 21:48:47 2016 Florian Saurs
//

#ifndef PROCESS_HPP_
# define PROCESS_HPP_

# include "ICommunication.hpp"
# include "Information.hh"

class		Process {
private:
  int			_pid;
  ICommunication	*_com;

public:
  Process(ICommunication *);
  ~Process() {}

  int			create(void *(*)(void *), void *);
  bool			checkAvailable();
  void			assign(const std::string &, Information);
};

typedef struct		s_processArgs {
  int			nbThread;
  ICommunication	*com;
}			t_processArgs;

#endif /* !PROCESS_HPP_ */
