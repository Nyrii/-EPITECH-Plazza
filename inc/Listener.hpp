//
// Listener.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:31 2016 guillaume wilmot
// Last update Tue Apr 19 17:49:07 2016 Florian Saurs
//

#ifndef LISTENER_HPP_
# define LISTENER_HPP_

# include "ThreadPool.hpp"
# include "Com.hpp"
# include "Process.hpp"
# include "Timer.hh"

class		Listener
{
public:
  Listener();
  ~Listener() {}

  void		init(int, Com *);
  void		*listen();
  bool		timeOut();

  static void	*start(void *);
  static void	handler(int);
  static void	setCom(Com *);
  static Com	*getCom(Com *);

  t_processState	*getTask(ThreadPool &);

private:
  Com			*_com;
  unsigned int		_nbThread;
  Timer			_timer;
};

#endif /* !LISTENER */
