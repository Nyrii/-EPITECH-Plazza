//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Wed Apr  6 14:20:53 2016 Florian Saurs
//

#ifndef SERVEURSOCKET_HPP_
# define SERVEURSOCKET_HPP_

# include "ASocket.hpp"

class	ServeurSocket : public ASocket
{
public:
  ServeurSocket();
  virtual	~ServeurSocket();

  int		create();
  int		destroy();
  std::string	read();
  int		write(std::string const &);
};

#endif /* !SERVEURSOCKET_HPP_ */
