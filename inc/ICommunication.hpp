//
// ICommunication.hpp for ICommunication in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Wed Apr  6 13:44:41 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 23:18:16 2016 Nyrandone Noboud-Inpeng
//

#ifndef ICOMMUNICATION_HPP_
# define ICOMMUNICATION_HPP_

# include <map>

typedef struct			s_processState
{
  std::map<int, std::string>	state;
}				t_processState;

class				ICommunication
{
public:
  virtual			~ICommunication() {};
  virtual int			create(int) = 0;
  virtual int			destroy() const = 0;
  virtual std::string		read() const = 0;
  virtual int			write(std::string const &) const = 0;
};

#endif /* !ICOMMUNICATION_HPP_ */
