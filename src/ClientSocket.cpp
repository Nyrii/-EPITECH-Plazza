//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Wed Apr 13 21:44:31 2016 Florian Saurs
//

#include <iostream>
#include "ClientSocket.hpp"
#include "Errors.hpp"

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
  if(connect(_sock, (sockaddr*)&_sin, sizeof(_sin)) != SOCKET_ERROR)
    std::cout << "client connected" << std::endl;
  else
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
  std::cout << "read" << std::endl;
  std::cout << "_sock = " << _sock << std::endl;
  if (::read(_sock, &state, sizeof(state)) == -1)
    {
      std::cout << "read" << std::endl;
      return (-1);
    }
  std::cout << "read" << std::endl;
  return (0);
}
int		ClientSocket::write(t_processState &state) const
{
  if (::write(_sock, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
