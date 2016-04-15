//
// Listener.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:31 2016 guillaume wilmot
// Last update Fri Apr 15 19:04:38 2016 guillaume wilmot
//

#ifndef LISTENER_HPP_
# define LISTENER_HPP_

# include "Thread.hpp"
# include "ICommunication.hpp"

class		Listener {
public:
  Listener();
  ~Listener() {}

  void		init(int, int);
  void		*listen();
  static void	*start(void *);

  t_processState	*getTask();

private:
  unsigned int  _id;
  unsigned int  _nbThread;
};

#endif /* !LISTENER */
