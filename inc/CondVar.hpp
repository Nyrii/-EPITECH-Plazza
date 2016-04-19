//
// CondVar.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:54:51 2016 guillaume wilmot
// Last update Tue Apr 19 17:39:22 2016 Florian Saurs
//

#ifndef CONDVAR_HPP_
# define CONDVAR_HPP_

# include "Mutex.hpp"

class CondVar
{
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
