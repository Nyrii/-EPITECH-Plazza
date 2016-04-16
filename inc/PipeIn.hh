//
// PipeIn.hh for PipeIn in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:13:57 2016 Nyrandone Noboud-Inpeng
// Last update Sat Apr 16 18:24:21 2016 guillaume wilmot
//

#ifndef PIPEIN_HH_
# define PIPEIN_HH_

# include <sys/select.h>
# include "ICommunication.hpp"
# include "IPipe.hpp"

class		PipeIn : public IPipe
{
public:
  PipeIn(std::string);
  ~PipeIn();
  PipeIn(PipeIn const &);
  PipeIn	&operator=(PipeIn const &);
  void		destroy() const;
  int		write(t_processState &);
  int		read(t_processState &);
  int		getWriteFd() const;
  int		getReadFd() const;
  void		setWriteFd(int const &);
  void		setReadFd(int const &);
private:
  int		_writeFd;
  std::string	_path;
};

#endif /* !PIPEIN_HH_ */
