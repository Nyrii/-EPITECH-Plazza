//
// CondThread.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:55:40 2016 guillaume wilmot
// Last update Thu Apr  7 18:47:37 2016 guillaume wilmot
//

#ifndef CONDTHREAD_HPP_
# define CONDTHREAD_HPP_

# include <stdlib.h>
# include "Thread.hpp"
# include "CondVar.hpp"

class		CondThread {
public:
  CondThread() {}
  ~CondThread() {}

  void		wake();
  void		assignOrder();

private:
  Thread	_thread;
  CondVar	_cond;
};

#endif /* !CONDTHREAD_HPP */
