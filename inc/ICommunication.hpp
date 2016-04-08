//
// ICommunication.hpp for ICommunication in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Wed Apr  6 13:44:41 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 10:33:20 2016 Florian Saurs
//

#ifndef ICOMMUNICATION_HPP_
# define ICOMMUNICATION_HPP_

# include <iostream>
# include <map>

typedef struct			s_processState
{
  int				id;
  std::string			fileName;
}				t_processState;

class				ICommunication
{
public:
  virtual			~ICommunication() {};
  virtual int			create(int) = 0;
  virtual int			destroy() const = 0;
  virtual void			read(s_processState &) const = 0;
  virtual void			write(s_processState &) const = 0;
};

#endif /* !ICOMMUNICATION_HPP_ */
