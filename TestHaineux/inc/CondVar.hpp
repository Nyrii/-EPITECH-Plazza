//
// CondVar.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 14:23:40 2016 guillaume wilmot
// Last update Tue Apr  5 14:59:22 2016 guillaume wilmot
//

#ifndef CONDVAR_HPP_
# define CONDVAR_HPP_

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
