//
// Sockets.cpp for plazza in /home/saurs_f/cpp_plazza/src/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Mon Apr 18 12:10:31 2016 Florian Saurs
// Last update Mon Apr 18 17:57:38 2016 Florian Saurs
//

#include "Sockets.hpp"
#include "ClientSocket.hpp"
#include "ServeurSocket.hpp"

Sockets::Sockets(int)
{
  _serv = new ServeurSocket();
  _client = new ClientSocket();
}

Sockets::~Sockets()
{
  destroy();
}

int	Sockets::write(t_processState &state) const
{
  return (_client->write(state));
}

int	Sockets::read(t_processState &state) const
{
  return (_serv->read(state));
}

int	Sockets::destroy() const
{
  delete _serv;
  delete _client;
  // unlink(_path.c_str());
  return (0);
}
