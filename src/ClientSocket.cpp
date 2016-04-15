//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Fri Apr 15 18:31:06 2016 Nyrandone Noboud-Inpeng
//

#include <iostream>
#include "ClientSocket.hpp"
#include "CommunicationError.hh"

ClientSocket::ClientSocket()
{}

ClientSocket::~ClientSocket()
{}

int		ClientSocket::create(int)
{
  _sock = socket(AF_INET, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sin);
  _crecsize = sizeof(_csin);
  _sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  _sin.sin_family = AF_INET;
  _sin.sin_port = 17030;
  if(connect(_sock, (sockaddr*)&_sin, sizeof(_sin)) == SOCKET_ERROR)
    throw CommunicationError("Error: connection impossible.");
  return (0);
}

int		ClientSocket::destroy() const
{
  closesocket(_sock);
  return (0);
}

int		ClientSocket::read(t_processState &state) const
{
  if (recv(_csock, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
int		ClientSocket::write(t_processState &state) const
{
  if (send(_csock, &state, sizeof(state), 0) == -1)
    return (-1);
  return (0);
}
