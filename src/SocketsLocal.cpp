//
// SocketsLocal.cpp for plazza in /home/saurs_f/cpp_plazza/src/
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.eu>
//
// Started on  Mon Apr 18 12:43:02 2016 Florian Saurs
// Last update Mon Apr 18 19:01:01 2016 Florian Saurs
//

#include "SocketsLocal.hpp"
#include "ClientSocketLocal.hpp"
#include "ServeurSocketLocal.hpp"

SocketsLocal::SocketsLocal(int id) : _id(id)
{
  _path = std::string("./socket") + std::to_string(_id);
  _serv = new ServeurSocketLocal(_path);
  _client = new ClientSocketLocal(_path);
  _a = 0;
}

SocketsLocal::~SocketsLocal()
{
  destroy();
}

int	SocketsLocal::write(t_processState &state) const
{
  if (_a == 0)
    {
      ++const_cast<SocketsLocal *>(this)->_a;
      return (_client->write(state));
    }
  else
  {
      --const_cast<SocketsLocal *>(this)->_a;
      return (_serv->write(state));
  }
}

int	SocketsLocal::read(t_processState &state) const
{
  if (_a == 0)
    {
      ++const_cast<SocketsLocal *>(this)->_a;
      return (_serv->read(state));
    }
  else
    {
      --const_cast<SocketsLocal *>(this)->_a;
      return (_client->read(state));
    }
}

int	SocketsLocal::destroy() const
{
  delete _serv;
  delete _client;
  unlink(_path.c_str());
  return (0);
}
