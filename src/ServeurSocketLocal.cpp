//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Mon Apr 18 11:58:22 2016 Florian Saurs
//

#include <iostream>
#include "ServeurSocketLocal.hpp"
#include "CommunicationError.hh"

ServeurSocketLocal::ServeurSocketLocal()
{}

ServeurSocketLocal::~ServeurSocketLocal()
{
  unlink(_path.c_str());
}

int		ServeurSocketLocal::create(int _id)
{
  struct sockaddr_un saddr;

  _path = std::string("./soLoc") + std::to_string(_id);
  unlink(_path.c_str());
  _socket = socket(AF_UNIX, SOCK_STREAM, 0);
  if (_socket != INVALID_SOCKET)
    {
      saddr.sun_family = AF_UNIX;
      strcpy(saddr.sun_path, _path.c_str());
      _unixSocket = saddr;
      _socketError = bind(_socket, (sockaddr*)&_unixSocket, sizeof(_unixSocket));
      if (_socketError == SOCKET_ERROR)
	throw CommunicationError("Error: bind error.");
      else
	_socketError = listen(_socket, 5);
    }
  else
    throw CommunicationError("Error: socket error.");
  return (0);
}

int		ServeurSocketLocal::destroy() const
{
  closesocket(_socket);
  return (0);
}

int		ServeurSocketLocal::read(t_processState &state) const
{
  if (::read(_socket, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}

int		ServeurSocketLocal::write(t_processState &state) const
{
  if (::write(_socket, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
