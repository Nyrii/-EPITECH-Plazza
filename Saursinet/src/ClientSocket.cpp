//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Mon Apr 18 18:14:01 2016 Florian Saurs
//

#include <iostream>
#include "ClientSocket.hpp"

ClientSocket::ClientSocket()
{
  _socket = socket(AF_INET, SOCK_STREAM, 0);
  _internetSocket.sin_addr.s_addr = inet_addr("127.0.0.1");
  _internetSocket.sin_family = AF_INET;
  _internetSocket.sin_port = 17030;
  if(connect(_socket, (sockaddr*)&_internetSocket, sizeof(_internetSocket)) == SOCKET_ERROR)
    std::cerr << "connection impossible" << std::endl;
}

ClientSocket::~ClientSocket()
{}

int		ClientSocket::destroy() const
{
  closesocket(_socket);
  return (0);
}

int		ClientSocket::read(char &state) const
{
  if (recv(_socket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
int		ClientSocket::write(char &state) const
{
  if (send(_socket, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
