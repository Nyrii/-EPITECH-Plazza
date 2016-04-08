//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Wed Apr  6 14:14:28 2016 Florian Saurs
//

#ifndef CLIENTSOCKET_HPP_
# define CLIENTSOCKET_HPP_

# include "ASocket.hpp"

class	ClientSocket : public ASocket
{
public:
  ClientSocket();
  virtual	~ClientSocket();

  int		create();
  int		destroy();
  std::string	read();
  int		write(std::string const &);
};

#endif /* !CLIENTSOCKET_HPP_ */
