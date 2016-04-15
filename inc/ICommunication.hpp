//
// ICommunication.hpp for ICommunication in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Wed Apr  6 13:44:41 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 23:33:49 2016 Florian Saurs
//

#ifndef ICOMMUNICATION_HPP_
# define ICOMMUNICATION_HPP_

# include <iostream>
# include <map>
# include "Information.hh"

enum	Packet {
  DEAD,
  ASSIGN,
  FREE
};

typedef struct			s_processState
{
  int				id;
  bool				free;
  Information			info;
  char				fileName[250];
  Packet			state;
}				t_processState;

class				ICommunication
{
public:
  virtual			~ICommunication() {};
  virtual int			destroy() const = 0;
  virtual int			read(t_processState &) const = 0;
  virtual int			write(t_processState &) const = 0;
};

#endif /* !ICOMMUNICATION_HPP_ */
