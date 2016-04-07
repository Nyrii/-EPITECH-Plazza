//
// SafeQueue.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:55:34 2016 guillaume wilmot
// Last update Wed Apr  6 23:55:34 2016 guillaume wilmot
//

#ifndef SAFEQUEUE_HPP_
# define SAFEQUEUE_HPP_

# include <stack>
# include "Mutex.hpp"

class SafeQueue {
public:
  SafeQueue() {}
  ~SafeQueue() {}

  void push(int);
  bool tryPop(int *);
  bool isFinished();
  void setFinished();

private:
  std::stack<int>	_queue;
  Mutex			_mutex;
  bool			_isFinished;
};

#endif /* !SAFEQUEUE_HPP */
