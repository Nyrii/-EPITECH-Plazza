//
// CondVar.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 14:23:40 2016 guillaume wilmot
// Last update Tue Apr  5 14:32:14 2016 guillaume wilmot
//

#ifndef CONDVAR_HPP_
# define CONDVAR_HPP_

class CondVar {
public:
  CondVar() {pthread_cond_init(_condition, NULL);}
  ~CondVar() {pthread_cond_destroy(_condition);}

  void			wait();
  void			signal();
  void			broadcast();
private:
  pthread_cond_t	_condition;
};

#endif /* !CONDVAR_HPP_ */
