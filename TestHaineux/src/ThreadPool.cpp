//
// ThreadPool.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 00:30:45 2016 guillaume wilmot
// Last update Fri Apr  8 19:15:40 2016 guillaume wilmot
//

#include "ScopedLock.hpp"
#include "ThreadPool.hpp"

ThreadPool::ThreadPool(int nbThread)
{
  _nbThread = nbThread;
  _working = 0;
}

int		ThreadPool::init(void *(*ptr)(void *))
{
  int		i;

  for (i = 0; i < _nbThread; i++)
    {
      CondThread	*thread;

      thread = new CondThread;
      thread->start(ptr, thread);
      _threads.push_back(thread);
    }
  return (0);
}

void		ThreadPool::callback()
{
  ScopedLock	lock(_mutex);

  std::cout << "Callback" << std::endl;
  assign(true);
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
  assign(false);
  return (0);
}

int		ThreadPool::assign(bool dec)
{
  t_queue	*elem;

  if (dec)
    _working--;
  std::cout << "Before Assign : " << _working << " " << _stack.size() << std::endl;
  if (_working >= _nbThread || _stack.size() == 0)
    return (-1);
  std::cout << "After Assign" << std::endl;
  elem = _stack.front();
  for (unsigned int i = 0; i < _threads.size(); i++)
    if (!_threads[i]->isWorking())
      {
	_stack.erase(_stack.begin());
	_working++;
	std::cout << "WTF1" << std::endl;
	_threads[i]->assignOrder(elem);
	std::cout << "WTF2" << std::endl;
	return (0);
      }
  std::cout << "Fail" << std::endl;
  return (0);
}
