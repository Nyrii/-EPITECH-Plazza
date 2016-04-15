//
// NamedPipe.hh for namedPipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:18:42 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 10:58:13 2016 Nyrandone Noboud-Inpeng
//

#ifndef NAMEDPIPE_HH_
# define NAMEDPIPE_HH_

# include "ICommunication.hpp"

class					NamedPipe : public ICommunication
{
public:
  NamedPipe();
  ~NamedPipe();
  NamedPipe(NamedPipe const &);
  NamedPipe				&operator=(NamedPipe const &);

  int					create(int);
  int					destroy() const;
  int					write(t_processState &) const;
  int					read(t_processState &) const;
  int					getId() const;
  std::string				getPath() const;
  int					getReadFd() const;
  int					getWriteFd() const;
  private:
  int					_id;
  int					_rfd;
  int					_wfd;
  std::string				_path;
};

#endif /* !NAMEDPIPE_HH_ */
