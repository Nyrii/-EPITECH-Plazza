//
// Communication.hpp for Communication in /home/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Sun Apr 17 17:32:19 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr 17 17:52:08 2016 Nyrandone Noboud-Inpeng
//

#ifndef COMMUNICATION_HPP_
# define COMMUNICATION_HPP_

# include "ICommunication.hpp"

class				Com : public ICommunication
{
public:
  virtual			~Com() {};
  virtual int			destroy() const = 0;
  virtual int			read(t_processState &) const = 0;
  virtual int			write(t_processState &) const = 0;
  Com				&operator<<(t_processState &ps)
    {
      write(ps);
      return (*this);
    }
  Com				&operator>>(t_processState &ps)
    {
      read(ps);
      return (*this);
    }
};

#endif /* !COMMUNICATION_HPP_ */
