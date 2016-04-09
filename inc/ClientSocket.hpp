//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Fri Apr  8 11:04:27 2016 Florian Saurs
//

#ifndef CLIENTSOCKET_HPP_
# define CLIENTSOCKET_HPP_

# include "ASocket.hpp"

class	ClientSocket : public ASocket
{
public:
  ClientSocket();
  ~ClientSocket();

  int		create(int);
  int		destroy() const;
  void		read(t_processState &) const;
  void		write(t_processState &) const;
};

#endif /* !CLIENTSOCKET_HPP_ */
