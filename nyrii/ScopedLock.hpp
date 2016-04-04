//
// ScopedLock.hpp for ScopedLock in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 21:31:07 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 22:00:54 2016 Nyrandone Noboud-Inpeng
//

#ifndef SCOPEDLOCK_HPP_
# define SCOPEDLOCK_HPP_

# include "mutex.hpp"

class			ScopedLock {
public:
  ScopedLock(Mutex &);
  ~ScopedLock();
private:
  Mutex			*_mutex;
};

#endif
