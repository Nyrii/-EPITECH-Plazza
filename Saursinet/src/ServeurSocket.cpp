
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Mon Apr 18 18:14:19 2016 Florian Saurs
//

#include <iostream>
#include "ServeurSocket.hpp"

ServeurSocket::ServeurSocket()
{
  _clientSocket = -1;
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _clientReceiveSize = sizeof(_clientInternetSocket);
  if (_socket != INVALID_SOCKET)
    {
      _internetSocket.sin_addr.s_addr = inet_addr("127.0.0.1");
      _internetSocket.sin_family = AF_INET;
      _internetSocket.sin_port = 17030;
      _socketError = bind(_socket, (sockaddr*)&_internetSocket, sizeof(_internetSocket));
      if (_socketError != SOCKET_ERROR)
	{
	  _socketError = listen(_socket, 1000000);
	  if (_socketError == SOCKET_ERROR)
	    std::cerr << "listen error" << std::endl;
	}
      else
      std::cerr << "bind error" << std::endl;
    }
  else
    std::cerr << "socket error" << std::endl;
}

ServeurSocket::~ServeurSocket()
{}

int		ServeurSocket::destroy() const
{
  closesocket(_clientSocket);
  closesocket(_socket);
  return (0);
}

int		ServeurSocket::read(char &state) const
{
  if (_clientSocket == -1)
    const_cast<ServeurSocket *>(this)->_clientSocket = accept(_socket, (sockaddr*)&_clientInternetSocket, const_cast<socklen_t *>(&_clientReceiveSize));
  if (recv(_clientSocket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
int		ServeurSocket::write(char &state) const
{
  if (send(_clientSocket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
