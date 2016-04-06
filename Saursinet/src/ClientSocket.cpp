//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Wed Apr  6 17:39:45 2016 Florian Saurs
//

#include <iostream>
#include "../inc/ClientSocket.hpp"

ClientSocket::ClientSocket()
{}

ClientSocket::~ClientSocket()
{}

int		ClientSocket::create()
{
  _sock = socket(AF_INET, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sin);
  _crecsize = sizeof(_csin);
  _sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  _sin.sin_family = AF_INET;
  _sin.sin_port = 17030;
  if(connect(_sock, (sockaddr*)&_sin, sizeof(_sin)) != SOCKET_ERROR)
    std::cout << "Connexion à " << inet_ntoa(_sin.sin_addr) << " sur le port " << htons(_sin.sin_port) << std::endl;
  else
    std::cout << "Impossible de se connecter" << std::endl;
  return (0);
}

int		ClientSocket::destroy()
{
  closesocket(_sock);
  return (0);
}

std::string	ClientSocket::read()
{
  char buffer[32];

  if(recv(_sock, buffer, 32, 0) != SOCKET_ERROR)
    std::cout << "Recu : " << buffer << std::endl;
  return (buffer);
}

int		ClientSocket::write(std::string const &)
{
  return (0);
}
