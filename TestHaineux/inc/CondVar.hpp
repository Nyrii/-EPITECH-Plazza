//
// CondVar.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:51 2016 guillaume wilmot
// Last update Thu Apr  7 23:16:17 2016 guillaume wilmot
//

#ifndef CONDVAR_HPP_
# define CONDVAR_HPP_

# include "Mutex.hpp"

class CondVar {
public:
  CondVar(Mutex &);
  ~CondVar();

  void			wait();
  void			signal();
  void			broadcast();
private:
  pthread_cond_t	_condition;
  Mutex			*_mutex;
};

#endif /* !CONDVAR_HPP_ */
