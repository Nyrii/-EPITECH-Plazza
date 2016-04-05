//
// ICondVar.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 14:23:40 2016 guillaume wilmot
// Last update Tue Apr  5 14:24:58 2016 guillaume wilmot
//

#ifndef ICONDVAR_HPP_
# define ICONDVAR_HPP_

class ICondVar {
public:
  virtual ~ICondVar() {}
  virtual void wait() = 0;
  virtual void signal() = 0;
  virtual void broadcast() = 0;
};

#endif /* !ICONDVAR_HPP_ */
