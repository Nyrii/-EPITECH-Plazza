//
// namedPipe.hh for namedPipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:18:42 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr 12 15:49:07 2016 Nyrandone Noboud-Inpeng
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
  std::string				read() const;
  void					write(t_processState &) const;
  void					read(t_processState &) const;
  int					getId() const;
  std::string				getPath() const;
  private:
  int					_id;
  int					_rfd;
  int					_wfd;
  std::string				_path;
};

#endif /* !NAMEDPIPE_HH_ */
