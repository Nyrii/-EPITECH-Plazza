//
// Pipes.hpp for Pipes in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 10:54:41 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr 16 17:51:36 2016 guillaume wilmot
//

#ifndef PIPES_HPP_
# define PIPES_HPP_

# include "ICommunication.hpp"
# include "IPipe.hpp"

class		Pipes : public ICommunication
{
public:
  Pipes(int);
  ~Pipes();

  int		write(t_processState &) const;
  int		read(t_processState &) const;
  int		create(int) { return (0); };
  int		destroy() const;
private:
  IPipe		*_out;
  IPipe		*_in;
  int		_id;
  std::string	_path;
};

#endif /* !PIPES_HPP_ */
