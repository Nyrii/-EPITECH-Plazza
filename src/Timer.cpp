//
// Timer.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr 15 22:52:38 2016 guillaume wilmot
// Last update Sat Apr 16 16:25:10 2016 guillaume wilmot
//

#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <exception>
#include <iostream>
#include <cstring>
#include "Timer.hh"

static void handler(int, siginfo_t *, void *)
{
  std::cout << "Timer Timed Out" << std::endl;
  exit(-1);
}

Timer::Timer()
{
    struct sigevent sev;
    struct sigaction sa;

    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);

    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGUSR1;
    sev.sigev_value.sival_ptr = &_id;

    if (timer_create(CLOCK_REALTIME, &sev, &_id) == -1)
      {
	std::cerr << "CreateTimer error" << std::endl;
	throw new std::exception;
      }
}

void			Timer::setTime(int val)
{
  struct itimerspec	value;

  memset(&value, 0, sizeof(value));
  value.it_value.tv_sec = val;
  value.it_value.tv_nsec = val * 1000000000;
  if (timer_settime(_id, 0, &value, NULL) == -1)
    {
      std::cerr << "ErrorSettime" << std::endl;
      throw new std::exception;
    }
}

bool			Timer::isElapsed()
{
  return (false);
  struct itimerspec	value;

  if (timer_gettime(_id, &value) == -1)
    {
      std::cerr << "ErrorGettime" << std::endl;
      throw new std::exception;
    }
  if (value.it_value.tv_nsec == 0)
    return (true);
  return (false);
}
