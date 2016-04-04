//
// ISafeQueue.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 20:36:43 2016 guillaume wilmot
// Last update Mon Apr  4 21:06:11 2016 guillaume wilmot
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
