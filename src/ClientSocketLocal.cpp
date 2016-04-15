//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Fri Apr 15 18:31:12 2016 Nyrandone Noboud-Inpeng
//

#include <iostream>
#include "ClientSocketLocal.hpp"
#include "CommunicationError.hh"

ClientSocketLocal::ClientSocketLocal()
{}

ClientSocketLocal::~ClientSocketLocal()
{}

int		ClientSocketLocal::create(int _id)
{
  struct sockaddr_un saddr;

  _path = std::string("./soLoc") + std::to_string(_id);
  _sock = socket(AF_UNIX, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sun);
  _crecsize = sizeof(_csun);
  saddr.sun_family = AF_UNIX;
  strcpy(saddr.sun_path, _path.c_str());
  _sun = saddr;
  if(connect(_sock, (sockaddr*)&_sun, sizeof(_sun)) == SOCKET_ERROR)
    throw CommunicationError("Error: local connection impossible.");
  return (0);
}

int		ClientSocketLocal::destroy() const
{
  closesocket(_sock);
  return (0);
}

int		ClientSocketLocal::read(t_processState &state) const
{
  if (::read(_sock, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}

int		ClientSocketLocal::write(t_processState &state) const
{
  if (::write(_sock, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
