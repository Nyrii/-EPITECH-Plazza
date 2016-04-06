//
// Listener.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:58:38 2016 guillaume wilmot
// Last update Thu Apr  7 01:51:53 2016 guillaume wilmot
//

/**/
#include <unistd.h>
/**/
#include <iostream>
#include "Listener.hpp"
#include "ThreadPool.hpp"

Listener::Listener()
{
  _id = 0;
  _nbThread = 0;
}

void		*toast(void *args)
{
  t_args	*toDo;

  toDo = reinterpret_cast<t_args *>(args);
  std::cout << toDo->order << " " << toDo->file << std::endl;
  toDo->callback->dec();
  return (NULL);
}

void		Listener::init(int nbThread, int id)
{
  _nbThread = nbThread;
  _id = id;
}

void		*Listener::listen()
{
  ThreadPool	threadPool(_nbThread);

  threadPool.queue(&toast, PHONE_NUMBER, "ma bite.txt");
  threadPool.queue(&toast, EMAIL_ADDRESS, "ma botte.txt");
  threadPool.queue(&toast, IP_ADDRESS, "ma batte.txt");
  threadPool.queue(&toast, PHONE_NUMBER, "ma bille.txt");
  threadPool.queue(&toast, EMAIL_ADDRESS, "ma balle.txt");
  threadPool.queue(&toast, IP_ADDRESS, "ma biche.txt");
  threadPool.assign();
  threadPool.assign();
  threadPool.assign();
  threadPool.assign();
  threadPool.assign();
  usleep(10000);
  threadPool.assign();
  sleep(1);
  return (NULL);
}

void		*Listener::start(void *args)
{
  Listener	_this;
  int		*tab;

  tab = reinterpret_cast<int *>(args);
  _this.init(tab[0], tab[1]);
  return (_this.listen());
}
