//
// IMutex.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr  4 18:55:40 2016 guillaume wilmot
// Last update Mon Apr  4 20:25:20 2016 guillaume wilmot
//

#ifndef IMUTEX_HPP_
# define IMUTEX_HPP_

class IMutex {
public:
  virtual ~IMutex(void) {}
  virtual void lock(void) = 0;
  virtual void unlock(void) = 0;
  virtual bool trylock(void) = 0;
};

#endif /* !IMUTEX_HPP */
