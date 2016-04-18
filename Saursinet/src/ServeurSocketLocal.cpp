//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Mon Apr 18 16:45:11 2016 Florian Saurs
//

#include <iostream>
#include "ServeurSocketLocal.hpp"
// #include "CommunicationError.hh"

ServeurSocketLocal::ServeurSocketLocal(std::string path)
{
  struct sockaddr_un socketAddress;

  _path = path;
  _clientSocket = -1;
  unlink(_path.c_str());
  _socket = socket(AF_UNIX, SOCK_STREAM, 0);
  _clientReceiveSize = sizeof(_clientUnixSocket);
  if (_socket != INVALID_SOCKET)
    {
      socketAddress.sun_family = AF_UNIX;
      strcpy(socketAddress.sun_path, _path.c_str());
      _unixSocket = socketAddress;
      _socketError = bind(_socket, (sockaddr*)&_unixSocket, sizeof(_unixSocket));
      if (_socketError == SOCKET_ERROR)
	std::cerr << "Error: bind error." << std::endl;
      else
	_socketError = listen(_socket, 5);
    }
  else
  std::cerr << "Error: socket error." << std::endl;
}

ServeurSocketLocal::~ServeurSocketLocal()
{
  unlink(_path.c_str());
}

int		ServeurSocketLocal::destroy() const
{
  closesocket(_socket);
  return (0);
}

int		ServeurSocketLocal::read(char &c) const
{
  if (_clientSocket == -1)
    if ((const_cast<ServeurSocketLocal *>(this)->_clientSocket = accept(_socket, (sockaddr*)&_clientUnixSocket, &const_cast<ServeurSocketLocal *>(this)->_clientReceiveSize)) == -1)
      std::cerr << "Error: accept error." << std::endl;
    std::cout << "read by server local" << std::endl;
  return (::read(_clientSocket, &c, sizeof(char)));
    return (-1);
    std::cout << "read by server local---------------------------" << c << std::endl;
  return (0);
}

int		ServeurSocketLocal::write(char &c) const
{
  if (_clientSocket == -1)
    if ((const_cast<ServeurSocketLocal *>(this)->_clientSocket = accept(_socket, (sockaddr*)&_clientUnixSocket, &const_cast<ServeurSocketLocal *>(this)->_clientReceiveSize)) == -1)
	std::cerr << "Error: accept error." << std::endl;
      std::cout << "write by server local" << std::endl;
  if (::write(_clientSocket, &c, sizeof(char)) == -1)
    return (-1);
    std::cout << "write by server local" << std::endl;

  return (0);
}
