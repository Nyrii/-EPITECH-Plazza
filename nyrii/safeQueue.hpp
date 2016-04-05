//
// safeQueue.hpp for safequeue in /Users/noboud_n/rendu/cpp_plazza/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Mon Apr  4 23:13:12 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr  4 23:43:16 2016 Nyrandone Noboud-Inpeng
//

#ifndef SAFEQUEUE_HPP_
# define SAFEQUEUE_HPP_

# include <stack>

class	ISafeQueue
{
  public:
  virtual ~ISafeQueue(void) {};
  virtual void push(int value) = 0;
  virtual bool tryPop(int *value) = 0;
  virtual bool isFinished(void) = 0;
  virtual void setFinished(void) = 0;
};

class			SafeQueue : public ISafeQueue
{
public:
  SafeQueue();
  ~SafeQueue();
  void			push(int value);
  bool			tryPop(int *value);
  bool			isFinished();
  void			setFinished();
private:
  std::stack<int>	_stack;
  Mutex			_mutex;
  bool			_isFinished;
};

#endif
