//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Mon Apr 18 16:44:56 2016 Florian Saurs
//

#include <iostream>
#include "ClientSocketLocal.hpp"

ClientSocketLocal::ClientSocketLocal(std::string path)
{
  struct sockaddr_un socketAddress;

  _path = path;
  _socket = socket(AF_UNIX, SOCK_STREAM, 0);
  socketAddress.sun_family = AF_UNIX;
  strcpy(socketAddress.sun_path, _path.c_str());
  _unixSocket = socketAddress;
  if(connect(_socket, (sockaddr*)&_unixSocket, sizeof(_unixSocket)) == SOCKET_ERROR)
    std::cerr << "Error: local connection impossible." << std::endl;
}

ClientSocketLocal::~ClientSocketLocal()
{}

int		ClientSocketLocal::destroy() const
{
  closesocket(_socket);
  return (0);
}

int		ClientSocketLocal::read(char &c) const
{
  std::cout << "read by client local" << std::endl;
  return (::read(_socket, &c, sizeof(char)));
    return (-1);
  std::cout << "read by client local--------------------------" << c << std::endl;
  return (0);
}

int		ClientSocketLocal::write(char &c) const
{
  std::cout << "write by client local" << std::endl;
  if (::write(_socket, &c, sizeof(char)) == -1)
    return (-1);
    std::cout << "write by client local" << std::endl;
  return (0);
}
