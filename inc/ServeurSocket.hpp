//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Tue Apr 12 16:58:23 2016 Saursinet
//

#ifndef SERVEURSOCKET_HPP_
# define SERVEURSOCKET_HPP_

# include "ASocket.hpp"

class	ServeurSocket : public ASocket
{
public:
  ServeurSocket();
  ~ServeurSocket();

  int		create(int);
  int		destroy() const;
  int		read(t_processState &) const;
  int		write(t_processState &) const;
};

#endif /* !SERVEURSOCKET_HPP_ */
