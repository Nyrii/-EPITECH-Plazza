//
// Thread.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 20:36:43 2016 guillaume wilmot
// Last update Mon Apr  4 20:46:56 2016 guillaume wilmot
//

#ifndef THREAD_HPP_
# define THREAD_HPP_

class		Thread {
public:
  Thread() {_started = 0;}
  ~Thread() {}

  void		start(void *(*ptr)(void *), void *arg) {pthread_create(&_thread, NULL, ptr, arg); _started = true;}
  void		join() {pthread_join(_thread, NULL);}
  bool		getStatus() const {return (_started);};
private:
  pthread_t	_thread;
  bool		_started;
};

#endif /* !THREAD_HPP */
