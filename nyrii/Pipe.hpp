//
// Pipe.hpp for Pipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:18:42 2016 Nyrandone Noboud-Inpeng
// Last update Tue Apr  5 23:24:25 2016 Nyrandone Noboud-Inpeng
//

#ifndef PIPE_HPP_
# define PIPE_HPP_

# include <map>
# include <vector>

class		IPipe
{
public:
  virtual		~IPipe() {};
  virtual int		create() = 0;
  virtual int		destroy() = 0;
  virtual std::string	read() = 0;
  virtual int		write(std::string const &) = 0;
};

class					NamedPipe : public IPipe
{
public:
  NamedPipe();
  ~NamedPipe();
  NamedPipe(NamedPipe const &);
  NamedPipe				&operator=(NamedPipe const &);

  int					create();
  int					destroy();
  std::string				read();
  int					write(std::string const &);

  std::vector<int>			getIdList() const;
  std::map<int, std::string>		getPipes() const;
  int					getId() const;
  int					getCurrentId() const;

  void					setCurrentId(int);

  private:
  int					_id;
  int					_currentId;
  std::vector<int>			_idList;
  std::map<int, std::string>		_namedPipe;
};

#endif /* !PIPE_HPP_ */
