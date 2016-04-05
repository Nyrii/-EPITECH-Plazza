//
// SafeQueue.cpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 21:04:01 2016 guillaume wilmot
// Last update Mon Apr  4 22:00:37 2016 guillaume wilmot
//

#include "SafeQueue.hpp"
#include "ScopedLock.hpp"

void		SafeQueue::push(int val)
{
  ScopedLock	lock(_mutex);

  if (!_isFinished)
    _queue.push(val);
}

bool		SafeQueue::tryPop(int *val)
{
  ScopedLock	lock(_mutex);

  if (!_queue.size())
    return (false);
  *val = _queue.top();
  _queue.pop();
  return (true);
}

bool		SafeQueue::isFinished()
{
  ScopedLock	lock(_mutex);

  return (_isFinished && !_queue.size() ? true : false);
}

void		SafeQueue::setFinished()
{
  ScopedLock	lock(_mutex);

  _isFinished = true;
}
