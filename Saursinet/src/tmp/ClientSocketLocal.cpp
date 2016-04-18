//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Mon Apr 18 15:37:52 2016 Florian Saurs
//

#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include "../inc/ClientSocketLocal.hpp"

ClientSocketLocal::ClientSocketLocal()
{}

ClientSocketLocal::~ClientSocketLocal()
{}

int		ClientSocketLocal::create()
{
  _sock = socket(AF_UNIX, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sun);
  _crecsize = sizeof(_csun);
  struct sockaddr_un saddr = {AF_UNIX, "server_socket"};
  _sun = saddr;
  if(connect(_sock, (sockaddr*)&_sun, sizeof(_sun)) != SOCKET_ERROR)
    std::cout << "Connexion à la socket en local" << std::endl;
  else
    std::cout << "Impossible de se connecter" << std::endl;
  return (0);
}

int		ClientSocketLocal::destroy()
{
  closesocket(_sock);
  return (0);
}

std::string	ClientSocketLocal::read()
{
  char	ch = 'A';

  // const int flags = fcntl(_sock, F_GETFL, 0);
  // if (!(flags & O_NONBLOCK))
  //   std::cout << "socket was already in blocking mode" << std::endl;
  // else
  //   std::cout << "socket was already in non- blocking mode" << std::endl;
  // fcntl(_sock, F_SETFL, flags ^ O_NONBLOCK);
  // send(_sock, &ch, 1, 0);
  // std::cout << "recv = " << recv(_sock, &ch, 1, MSG_WAITALL) << std::endl;
  // std::cout << "recv = " << recv(_sock, &ch, 1, MSG_WAITALL) << std::endl;
  // std::cout << "recv = " << recv(_sock, &ch, 1, MSG_WAITALL) << std::endl;
while (1)
    {
      ::write(_sock, &ch, 1);
      ::read(_sock, &ch, 1);
      std::cout << "Char received from server " << ch << std::endl;
    }
  // ::read(_sock, &ch, 1);
  // ::read(_sock, &ch, 1);
  // ::read(_sock, &ch, 1);
  // ::read(_sock, &ch, 1);
  close(_sock);
  return ("");
}

int		ClientSocketLocal::write(std::string const &)
{
  return (0);
}
