//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Wed Apr  6 15:38:32 2016 Florian Saurs
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
  _sin.sin_port = htons(PORT);
  if(connect(_sock, (SOCKADDR*)&_sin, sizeof(_sin)) != SOCKET_ERROR)
    printf("Connexion à %s sur le port %d\n", inet_ntoa(_sin.sin_addr), htons(_sin.sin_port));
  else
    printf("Impossible de se connecter\n");
  return (EXIT_SUCCESS);
}

int		ClientSocket::destroy()
{
  closesocket(_sock);
  return (EXIT_SUCCESS);
}

std::string	ClientSocket::read()
{
  char buffer[32];

  if(recv(_sock, buffer, 32, 0) != SOCKET_ERROR)
    printf("Recu : %s\n", buffer);
  return ("");
}

int		ClientSocket::write(std::string const &)
{
  return (EXIT_SUCCESS);
}
