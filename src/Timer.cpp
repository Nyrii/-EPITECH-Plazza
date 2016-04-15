//
// Timer.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr 15 22:52:38 2016 guillaume wilmot
// Last update Fri Apr 15 22:56:56 2016 guillaume wilmot
//

#include <time.h>
#include "Timer.hh"

void		Timer::setTime(int time)
{
  _time = time;
  _tick = clock();
}

bool		Timer::isElapsed()
{
  _time -= clock() - _tick;
  if (_time <= 0)
    return (true);
  return (false);
}
