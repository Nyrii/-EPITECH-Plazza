//
// CondVar.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 14:58:51 2016 guillaume wilmot
// Last update Tue Apr  5 15:23:49 2016 guillaume wilmot
//

#include "CondVar.hpp"

Condvar::CondVar(Mutex &mutex)
{
  _mutex = &mutex;
  pthread_cond_init(_condition, NULL);
}

Condvar::~CondVar()
{
  pthread_cond_destroy(_condition);
}

void		Condvar::wait()
{
  pthread_cond_wait (_condition, _mutex);
}

void		Condvar::signal()
{
  pthread_cond_signal(_condition);
}

void		Condvar::broadcast()
{
  pthread_cond_broadcast(_condition);
}
