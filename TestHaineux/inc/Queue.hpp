//
// Queue.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 23:32:47 2016 guillaume wilmot
// Last update Thu Apr  7 23:48:53 2016 guillaume wilmot
//

#ifndef QUEUE_HPP_
# define QUEUE_HPP_

# include "ThreadPool.hpp"

class	ThreadPool;

enum Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
  };

typedef struct s_queue  t_queue;

typedef struct          s_args {
  ThreadPool            *callback;
  Information           order;
  std::string           file;
}                       t_args;

struct                  s_queue {
  t_args                *args;
  void                  *(*ptr)(void *);
};

#endif /*!QUEUE_HPP_ */
