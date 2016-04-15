//
// Listener.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:31 2016 guillaume wilmot
// Last update Fri Apr 15 22:49:37 2016 Florian Saurs
//

#ifndef LISTENER_HPP_
# define LISTENER_HPP_

# include "ThreadPool.hpp"
# include "Thread.hpp"
# include "ICommunication.hpp"
# include "Process.hpp"

class		Listener {
public:
  Listener();
  ~Listener() {}

  void		init(int, ICommunication *);
  void		*listen();
  static void	*start(void *);

  t_processState	*getTask(ThreadPool &);

private:
  ICommunication	*_com;
  unsigned int		_nbThread;
};

#endif /* !LISTENER */
