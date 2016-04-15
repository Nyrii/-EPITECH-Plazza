//
// Pipes.hpp for Pipes in /Users/noboud_n/rendu/cpp_plazza/inc/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Fri Apr 15 10:54:41 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 12:30:41 2016 Nyrandone Noboud-Inpeng
//

#ifndef PIPES_HPP_
# define PIPES_HPP_

# include "ICommunication.hpp"

class		Pipe
{
public:
  virtual	~Pipe() {};
  virtual void	destroy() const = 0;
  virtual int	write(t_processState &) const = 0;
  virtual int	read(t_processState &) const = 0;
};

class		PipeOut : public Pipe
{
public:
  PipeOut() {};
  ~PipeOut() {};
  PipeOut(PipeOut const &);
  PipeOut	&operator=(PipeOut const &);
  void		destroy() const;
  int		write(t_processState &) const;
  int		read(t_processState &) const;
  int		getReadFd() const;
  void		setReadFd(int const &);
private:
  int		_readFd;
};

class		PipeIn : public Pipe
{
public:
  PipeIn() {};
  ~PipeIn() {};
  PipeIn(PipeIn const &);
  PipeIn	&operator=(PipeIn const &);
  void		destroy() const;
  int		write(t_processState &) const;
  int		read(t_processState &) const;
  int		getWriteFd() const;
  void		setWriteFd(int const &);
private:
  int		_writeFd;
};

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
  PipeOut	_out;
  PipeIn	_in;
  int		_id;
  std::string	_path;
};

#endif /* !PIPES_HPP_ */
