//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Fri Apr 15 18:31:54 2016 Nyrandone Noboud-Inpeng
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
  _sock = socket(AF_UNIX, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sun);
  _crecsize = sizeof(_csun);
  if (_sock != INVALID_SOCKET)
    {
      saddr.sun_family = AF_UNIX;
      strcpy(saddr.sun_path, _path.c_str());
      _sun = saddr;
      _sock_err = bind(_sock, (sockaddr*)&_sun, _recsize);
      if (_sock_err == SOCKET_ERROR)
	throw CommunicationError("Error: bind error.");
      else
	_sock_err = listen(_sock, 5);
    }
  else
    throw CommunicationError("Error: socket error.");
  return (0);
}

int		ServeurSocketLocal::destroy() const
{
  closesocket(_sock);
  return (0);
}

int		ServeurSocketLocal::read(t_processState &state) const
{
  if (::read(_sock, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}

int		ServeurSocketLocal::write(t_processState &state) const
{
  if (::write(_sock, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
