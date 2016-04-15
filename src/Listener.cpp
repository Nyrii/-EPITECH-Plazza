//
// Listener.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:58:38 2016 guillaume wilmot
// Last update Fri Apr 15 16:27:09 2016 guillaume wilmot
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

void		Listener::init(int nbThread, int id)
{
  _nbThread = nbThread;
  _id = id;
}

void            *toast(void *arg)
{
  t_args        *args;

  args = reinterpret_cast<t_args *>(arg);
  std::cout << args->order << " " << args->file << std::endl;
  usleep(rand() % 100000);
  return (NULL);
}

void		*Listener::listen()
{
  // ThreadPool	threadPool(_nbThread);
  // t_processState      *struc = new t_processState;
  // int                 retRead;

  // threadPool.init(&CondThread::begin);
  // _isFinished = false;
  // while (!_isFinished)
  //   {
  //     memset(struc, 0, sizeof(*struc));
  //     struc->id = 0;
  //     struc->free = false;
  //     struc->fileName = new std::string("");
  //     serv->write(*struc);
  //     execParse(fileName, _type);
  //     struc->free = true;
  //     serv->write(*struc);
  //     if ((retRead = serv->read(*struc)) == 0 && struc->id == 0)
  // 	fileName = *(struc->fileName);
  //     else if ((retRead == 0 && struc->id == -1) || retRead == -1)
  // 	_isFinished = true;
  //   }
  // exit(0);

  // sleep(1);
  // srand(time(NULL));
  // for (unsigned int i = 0; i < _nbThread * 2; i++)
  //   {
  //     /* Debug */
  //     std::string		Test = "EXEC xxxxxxx";
  //     Test[11] = i % 10 + '0';
  //     Test[10] = (i / 10) % 10 + '0';
  //     Test[9] = (i / 100) % 10 + '0';
  //     Test[8] = (i / 1000) % 10 + '0';
  //     Test[7] = (i / 10000) % 10 + '0';
  //     Test[6] = (i / 100000) % 10 + '0';
  //     Test[5] = (i / 1000000) % 10 + '0';
  //     /**/
  //     threadPool.queue(&toast, PHONE_NUMBER, "\033[01;32m" + Test + "\033[0m");
  //     usleep(rand() % 10000);
  //   }
  // while (1) sleep(1);
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
