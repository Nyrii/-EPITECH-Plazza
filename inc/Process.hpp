//
// Process.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:56:05 2016 guillaume wilmot
// Last update Tue Apr 19 17:51:22 2016 Florian Saurs
//

#ifndef PROCESS_HPP_
# define PROCESS_HPP_

# include "Com.hpp"

class		Process
{
private:
  pid_t			_pid;
  Com			*_com;

public:
  Process(Com *);
  ~Process();

  pid_t			getPid() const {return (_pid);}
  int			create(void *(*)(void *), void *);
  bool			checkAvailable();
  bool			assign(const std::string &, Information);
  Com			*getCom() const;
};

typedef struct		s_processArgs {
  int			nbThread;
  Com			*com;
}			t_processArgs;

#endif /* !PROCESS_HPP_ */
