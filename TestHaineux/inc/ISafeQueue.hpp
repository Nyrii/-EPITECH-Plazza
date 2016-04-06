//
// ISafeQueue.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Wed Apr  6 23:55:54 2016 guillaume wilmot
// Last update Wed Apr  6 23:55:54 2016 guillaume wilmot
//

#ifndef ISAFEQUEUE_HPP_
# define ISAFEQUEUE_HPP_

class ISafeQueue {
public:
  virtual ~ISafeQueue() {}

  virtual void push(int) = 0;
  virtual bool tryPop(int *) = 0;
  virtual bool isFinished() = 0;
  virtual void setFinished() = 0;
};

#endif /* !ISAFEQUEUE_HPP */
