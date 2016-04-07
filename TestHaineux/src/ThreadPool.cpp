//
// ThreadPool.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 00:30:45 2016 guillaume wilmot
// Last update Thu Apr  7 17:52:29 2016 guillaume wilmot
//

#include "ScopedLock.hpp"
#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int nbThread)
{
  _nbThread = nbThread;
  _working = 0;
}

void		ThreadPool::dec()
{
  ScopedLock	lock(_mutex);

  _working--;
}

int		ThreadPool::queue(void *(*ptr)(void *), Information order, const std::string &file)
{
  ScopedLock	lock(_mutex);

  t_queue	*elem = new t_queue;

  if (_working >= _nbThread * 2)
    return (-1);
  elem->args = new t_args;
  elem->args->callback = this;
  elem->args->order = order;
  elem->args->file = file;
  elem->ptr = ptr;
  _stack.push_back(elem);
  return (0);
}

int		ThreadPool::assign()
{
  ScopedLock	lock(_mutex);

  // Thread	*thread;
  t_queue	*elem;

  if (_working >= _nbThread || _stack.size() == 0)
    return (-1);
  elem = _stack.front();
  _stack.erase(_stack.begin());
  // thread = new Thread;
  _working++;
  // thread->start(elem->ptr, elem->args);
  // _threads.push_back(thread);
  delete elem;
  return (0);
}
