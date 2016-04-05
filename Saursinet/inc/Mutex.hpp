//
// IMutex.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 18:55:40 2016 guillaume wilmot
// Last update Mon Apr  4 19:38:45 2016 Florian Saurs
//

#include <pthread.h>
#include "IMutex.hpp"

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
