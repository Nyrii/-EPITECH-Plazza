//
// Communication.hpp for Communication in /home/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Sun Apr 17 17:32:19 2016 Nyrandone Noboud-Inpeng
// Last update Mon Apr 18 16:32:08 2016 Florian Saurs
//

#ifndef COM_HPP_
# define COM_HPP_


class				Com
{
public:
  virtual			~Com() {};
  virtual int			destroy() const = 0;
  virtual int			read(char &) const = 0;
  virtual int			write(char &) const = 0;
};

#endif /* !COM_HPP_ */
