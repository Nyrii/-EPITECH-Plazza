//
// Timer.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr 15 22:52:38 2016 guillaume wilmot
// Last update Tue Apr 19 17:36:26 2016 Florian Saurs
//

#include <time.h>
#include <signal.h>
#include <cstring>
#include "Timer.hh"
#include "TimerError.hh"

Timer::Timer()
{
  struct sigevent sev;

  sev.sigev_notify = SIGEV_SIGNAL;
  sev.sigev_signo = SIGUSR1;
  sev.sigev_value.sival_ptr = &_id;

  if (timer_create(CLOCK_REALTIME, &sev, &_id) == -1)
    throw TimerError("Error: Timer creation failed.");
}

void			Timer::setTime(int val)
{
  struct itimerspec	value;

  memset(&value, 0, sizeof(value));
  value.it_value.tv_sec = val;
  value.it_value.tv_nsec = val * 1000000000;
  if (timer_settime(_id, 0, &value, NULL) == -1)
    throw TimerError("Error: Timer setting time failed.");
}

bool			Timer::isElapsed()
{
  return (false);
  struct itimerspec	value;

  if (timer_gettime(_id, &value) == -1)
    throw TimerError("Error: Timer getter failed.");
  if (value.it_value.tv_nsec == 0)
    return (true);
  return (false);
}
