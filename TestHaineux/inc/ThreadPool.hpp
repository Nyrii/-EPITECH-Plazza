//
// ThreadPool.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Thu Apr  7 00:29:53 2016 guillaume wilmot
// Last update Thu Apr  7 18:15:53 2016 guillaume wilmot
//

#ifndef THREADPOOL_HPP_
# define THREADPOOL_HPP_

# include <iostream>
# include <vector>
# include "Mutex.hpp"
# include "CondThread.hpp"

/* TO REPLACE WITH SAURS' */
enum Information
  {
    PHONE_NUMBER,
    EMAIL_ADDRESS,
    IP_ADDRESS
  };
/**/

typedef struct s_queue	t_queue;

class			ThreadPool {
public:
  ThreadPool(int);
  ~ThreadPool() {}

  void			dec();
  void			inc();
  int			assign();
  int			queue(void *(*)(void *), Information, const std::string &);

private:
  int				_nbThread;
  int				_working;
  Mutex				_mutex;
  std::vector<CondThread *>	_threads;
  std::vector<t_queue *>	_stack;
};

typedef struct		s_args {
  ThreadPool		*callback;
  Information		order;
  std::string		file;
}			t_args;

struct			s_queue {
  t_args		*args;
  void			*(*ptr)(void *);
};

#endif /* !THREADPOOL */
