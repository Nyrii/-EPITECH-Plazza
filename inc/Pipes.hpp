//
// Pipes.hpp for Pipes in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 10:54:41 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr 17 17:43:50 2016 Nyrandone Noboud-Inpeng
//

#ifndef PIPES_HPP_
# define PIPES_HPP_

# include "Communication.hpp"
# include "IPipe.hpp"

class			Pipes : public Com
{
public:
  Pipes(int);
  ~Pipes();

  int			write(t_processState &) const;
  int			read(t_processState &) const;
  int			create(int) { return (0); };
  int			destroy() const;
private:
  IPipe			*_out;
  IPipe			*_in;
  int			_id;
  std::string		_path;
};

#endif /* !PIPES_HPP_ */
