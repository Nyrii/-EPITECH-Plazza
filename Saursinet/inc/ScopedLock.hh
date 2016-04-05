//
// ScopedLock.hh for  in /home/saurs_f/cpp_plazza/Saursinet/inc
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Mon Apr  4 21:02:15 2016 Florian Saurs
// Last update Mon Apr  4 21:14:31 2016 Florian Saurs
//

#ifndef SCOPEDLOCK_HH_
# define SCOPEDLOCK_HH_

# include "Mutex.hpp"

class	ScopedLock
{
  Mutex	*_mutex;

public:
  ScopedLock() {_mutex = new Mutex(); _mutex->lock();};
  ~ScopedLock() {_mutex->unlock();};
};

#endif /* !SCOPEDLOCK_HH_ */
