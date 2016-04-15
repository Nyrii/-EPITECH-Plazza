//
// PipeIn.hh for PipeIn in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 18:13:57 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 18:25:32 2016 Nyrandone Noboud-Inpeng
//

#ifndef PIPEIN_HH_
# define PIPEIN_HH_

# include "ICommunication.hpp"
# include "IPipe.hpp"

class		PipeIn : public IPipe
{
public:
  PipeIn();
  ~PipeIn();
  PipeIn(PipeIn const &);
  PipeIn	&operator=(PipeIn const &);
  void		destroy() const;
  int		write(t_processState &) const;
  int		read(t_processState &) const;
  int		getWriteFd() const;
  int		getReadFd() const;
  void		setWriteFd(int const &);
  void		setReadFd(int const &);
private:
  int		_writeFd;
};

#endif /* !PIPEIN_HH_ */
