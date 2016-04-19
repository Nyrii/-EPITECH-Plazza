//
// ThreadPool.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 00:29:53 2016 guillaume wilmot
// Last update Tue Apr 19 17:54:46 2016 Florian Saurs
//

#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

# include <iostream>
# include <vector>
# include "Mutex.hpp"
# include "CondThread.hpp"
# include "Queue.hpp"
# include "Timer.hh"

class			CondThread;

class			ThreadPool {
public:
  ThreadPool(int);
  ~ThreadPool() {}

  int			callback(CondThread *);
  int			assign(CondThread *, bool);
  int			tryAssign();
  int			init(void *(*)(void *));
  int			queue(void *(*)(void *), Information, const std::string &);
  unsigned int		getQueueSize();
  unsigned int		getWorking();
  unsigned int		getTotalOrders();
  void			setTimer(Timer *);

private:
  int				_nbThread;
  int				_working;
  Mutex				_mutex;
  Timer				*_timer;
  std::vector<CondThread *>	_threads;
  std::vector<t_queue *>	_stack;
};

#endif /* !THREADPOOL */
