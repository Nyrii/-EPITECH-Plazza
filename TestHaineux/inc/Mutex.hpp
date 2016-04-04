//
// IMutex.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 18:55:40 2016 guillaume wilmot
// Last update Mon Apr  4 20:31:26 2016 guillaume wilmot
//

#ifndef MUTEX_HPP_
# define MUTEX_HPP_

# include "IMutex.hpp"

class Mutex : public IMutex {
public:
  Mutex() {pthread_mutex_init(&_mutex, NULL);}
  ~Mutex(void) {}

  void lock(void) {pthread_mutex_lock(&_mutex);}
  void unlock(void) {pthread_mutex_unlock(&_mutex);}
  bool trylock(void) {return (pthread_mutex_trylock(&_mutex));}
private:
  pthread_mutex_t	_mutex;
};

#endif /* !MUTEX_HPP */
