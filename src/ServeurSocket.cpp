//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Thu Apr 14 12:09:09 2016 Florian Saurs
//

#include <iostream>
#include "ServeurSocket.hpp"
#include "Errors.hpp"

ServeurSocket::ServeurSocket()
{}

ServeurSocket::~ServeurSocket()
{}

int		ServeurSocket::create(int)
{
  _csock = -1;
  _sock = socket(AF_INET, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sin);
  _crecsize = sizeof(_csin);
  if (_sock != INVALID_SOCKET)
    {
      _sin.sin_addr.s_addr = inet_addr("127.0.0.1");
      _sin.sin_family = AF_INET;
      _sin.sin_port = 17030;
      _sock_err = bind(_sock, (sockaddr*)&_sin, _recsize);
      if (_sock_err != SOCKET_ERROR)
	{
	  // 5 is the number max of connection
	  _sock_err = listen(_sock, 5);
	  if (_sock_err == SOCKET_ERROR)
	    throw CommunicationError("Error: listen error.");
	}
      else
	throw CommunicationError("Error: bind error.");
    }
  else
    throw CommunicationError("Error: socket error.");
  return (0);
}

int		ServeurSocket::destroy() const
{
  closesocket(_csock);
  closesocket(_sock);
  return (0);
}

int		ServeurSocket::read(t_processState &state) const
{
  if (_csock == -1)
    const_cast<ServeurSocket *>(this)->_csock = accept(_sock, (sockaddr*)&_csin, const_cast<socklen_t *>(&_crecsize));
  if (recv(_csock, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
int		ServeurSocket::write(t_processState &state) const
{
  if (send(_csock, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
