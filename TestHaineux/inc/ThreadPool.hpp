//
// ThreadPool.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 00:29:53 2016 guillaume wilmot
// Last update Fri Apr  8 17:04:01 2016 guillaume wilmot
//

#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

# include <iostream>
# include <vector>
# include "Mutex.hpp"
# include "CondThread.hpp"
# include "Queue.hpp"

class			CondThread;

class			ThreadPool {
public:
  ThreadPool(int);
  ~ThreadPool() {}

  void			callback();
  int			assign(bool);
  int			init(void *(*)(void *));
  int			queue(void *(*)(void *), Information, const std::string &);

private:
  int				_nbThread;
  int				_working;
  Mutex				_mutex;
  std::vector<CondThread *>	_threads;
  std::vector<t_queue *>	_stack;
};

#endif /* !THREADPOOL */
