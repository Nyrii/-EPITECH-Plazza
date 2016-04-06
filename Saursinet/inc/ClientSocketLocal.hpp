//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Wed Apr  6 15:58:17 2016 Florian Saurs
//

#ifndef CLIENTSOCKETLOCAL_HPP_
# define CLIENTSOCKETLOCAL_HPP_

# include "ASocket.hpp"

class	ClientSocketLocal : public ASocket
{
public:
  ClientSocketLocal();
  virtual	~ClientSocketLocal();

  int		create();
  int		destroy();
  std::string	read();
  int		write(std::string const &);
};

#endif /* !CLIENTSOCKETLOCAL_HPP_ */
