//
// Sockets.hpp for plazza in /home/saurs_f/cpp_plazza/inc/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Mon Apr 18 12:11:38 2016 Florian Saurs
// Last update Mon Apr 18 18:21:42 2016 Florian Saurs
//

#ifndef SOCKETS_HPP_
# define SOCKETS_HPP_

# include "ASocket.hpp"

class	Sockets : public ASocket
{
public:
  Sockets(int);
  ~Sockets();

  int			write(char &) const;
  int			read(char &) const;
  int			destroy() const;

private:
  ASocket		*_serv;
  ASocket		*_client;
  int			_id;
  int			_a;
};

#endif /* !SOCKETS_HPP_ */
