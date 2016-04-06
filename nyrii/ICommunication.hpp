//
// ICommunication.hpp for ICommunication in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Wed Apr  6 13:44:41 2016 Nyrandone Noboud-Inpeng
// Last update Wed Apr  6 14:46:46 2016 Nyrandone Noboud-Inpeng
//

#ifndef ICOMMUNICATION_HPP_
# define ICOMMUNICATION_HPP_

class			ICommunication
{
public:
  virtual		~ICommunication() {};
  virtual int		create(int) = 0;
  virtual int		destroy() = 0;
  virtual std::string	read() = 0;
  virtual int		write(std::string const &) = 0;
};

#endif /* !ICOMMUNICATION_HPP_ */
