//
// Thread.hpp for Thread in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 22:09:19 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 23:03:47 2016 Nyrandone Noboud-Inpeng
//

#ifndef THREAD_HPP_
# define THREAD_HPP_

enum		Status
{
  STANDBY,
  RUNNING,
  DEAD
};

class		IThread
{
public:
  virtual	~IThread() {};
  virtual void	start(void *(*)(void *)) = 0;
  virtual void	waitDeath() = 0;
};

class			Thread : public IThread
{
public:
  Thread();
  ~Thread();
  void			start(void *(*)(void *));
  void			waitDeath();
private:
  Status		_status;
  pthread_t		_pth;
};

#endif
