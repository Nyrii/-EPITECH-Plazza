//
// Process.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:05 2016 guillaume wilmot
// Last update Sun Apr 17 17:50:45 2016 Nyrandone Noboud-Inpeng
//

#ifndef PROCESS_HPP_
# define PROCESS_HPP_

# include "Communication.hpp"
# include "Information.hh"

class		Process {
private:
  int			_pid;
  Com			*_com;

public:
  Process(Com *);
  ~Process();

  int			create(void *(*)(void *), void *);
  bool			checkAvailable();
  bool			assign(const std::string &, Information);
};

typedef struct		s_processArgs {
  int			nbThread;
  Com			*com;
}			t_processArgs;

#endif /* !PROCESS_HPP_ */
