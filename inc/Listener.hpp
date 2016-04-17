//
// Listener.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:31 2016 guillaume wilmot
// Last update Sun Apr 17 17:49:50 2016 Nyrandone Noboud-Inpeng
//

#ifndef LISTENER_HPP_
# define LISTENER_HPP_

# include "ThreadPool.hpp"
# include "Thread.hpp"
# include "Communication.hpp"
# include "Process.hpp"
# include "Timer.hh"

class		Listener {
public:
  Listener();
  ~Listener() {}

  void		init(int, Com *);
  void		*listen();
  bool		timeOut();
  static void	*start(void *);

  t_processState	*getTask(ThreadPool &);

private:
  ICommunication	*_com;
  unsigned int		_nbThread;
  Timer			_timer;
};

#endif /* !LISTENER */
