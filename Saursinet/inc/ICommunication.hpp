//
// ICommunication.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Wed Apr  6 13:30:57 2016 Florian Saurs
// Last update Wed Apr  6 13:32:15 2016 Florian Saurs
//

#ifndef ICOMMUNICATION_HPP_
# define ICOMMUNICATION_HPP_

# include <iostream>

class	ICommunication
{
public:
  virtual		~ICommunication() {};
  virtual int		create() = 0;
  virtual int		destroy() = 0;
  virtual std::string	read() = 0;
  virtual int		write(std::string const &) = 0;
};

#endif /* !ICOMMUNICATION_HPP_ */
