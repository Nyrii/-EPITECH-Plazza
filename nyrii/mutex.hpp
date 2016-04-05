//
// mutex.hh for mutex in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 21:11:55 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 21:31:48 2016 Nyrandone Noboud-Inpeng
//

#ifndef MUTEX_HPP_
# define MUTEX_HPP_

class		IMutex {
public:
  virtual	~IMutex(void) {};
  virtual void	lock(void) = 0;
  virtual void	unlock(void) = 0;
  virtual bool	trylock(void) = 0;
};

class			Mutex : public IMutex {
public:
  Mutex();
  ~Mutex();
  void			lock(void);
  void			unlock(void);
  bool			trylock(void);
private:
  pthread_mutex_t	_mutex;
};

#endif
