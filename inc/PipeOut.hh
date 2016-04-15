//
// PipeOut.hh for PipeOut in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:07:10 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 18:25:48 2016 Nyrandone Noboud-Inpeng
//

#ifndef PIPEOUT_HH_
# define PIPEOUT_HH_

# include "ICommunication.hpp"
# include "IPipe.hpp"

class		PipeOut : public IPipe
{
public:
  PipeOut();
  ~PipeOut();
  PipeOut(PipeOut const &);
  PipeOut	&operator=(PipeOut const &);
  void		destroy() const;
  int		write(t_processState &) const;
  int		read(t_processState &) const;
  int		getReadFd() const;
  int		getWriteFd() const;
  void		setReadFd(int const &);
  void		setWriteFd(int const &);
private:
  int		_readFd;
};

#endif /* !PIPEOUT_HH_ */
