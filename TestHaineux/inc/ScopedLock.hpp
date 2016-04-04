//
// ScopedLock.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 20:07:25 2016 guillaume wilmot
// Last update Mon Apr  4 20:35:17 2016 guillaume wilmot
//

#ifndef SCOPEDLOCK_HPP_
# define SCOPEDLOCK_HPP_

# include "Mutex.hpp"

class ScopedLock {
public:
  ScopedLock(Mutex &mutex) {_lock = &mutex; _lock->lock();}
  ~ScopedLock() {_lock->unlock();}
private:
  Mutex		*_lock;
};

#endif /* !SCOPEDLOCK_HPP_ */
