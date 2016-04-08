//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Fri Apr  8 17:44:43 2016 Florian Saurs
//

#include <iostream>
#include "../inc/ClientSocketLocal.hpp"

ClientSocketLocal::ClientSocketLocal()
{}

ClientSocketLocal::~ClientSocketLocal()
{}

int		ClientSocketLocal::create(int)
{
  struct sockaddr_un saddr;

  _sock = socket(AF_UNIX, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sun);
  _crecsize = sizeof(_csun);
  // struct sockaddr_un saddr = {AF_UNIX, };
  saddr.sun_family = AF_UNIX;
  strcpy(saddr.sun_path, "server_socket");
  _sun = saddr;
  if(connect(_sock, (sockaddr*)&_sun, sizeof(_sun)) != SOCKET_ERROR)
    std::cout << "Connexion à la socket en local" << std::endl;
  else
    std::cout << "Impossible de se connecter" << std::endl;
  return (0);
}

int		ClientSocketLocal::destroy() const
{
  closesocket(_sock);
  return (0);
}

void		ClientSocketLocal::read(t_processState &) const
{
  char	ch = 'A';

  ::write(_sock, &ch, 1);
  ::read(_sock, &ch, 1);
  std::cout << "Char received from server " << ch << std::endl;
  close(_sock);
}

void		ClientSocketLocal::write(t_processState &) const
{}
