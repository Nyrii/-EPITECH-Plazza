//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Tue Apr 12 16:57:48 2016 Saursinet
//

#include <iostream>
#include "ServeurSocket.hpp"
#include "Errors.hpp"

ServeurSocket::ServeurSocket()
{}

ServeurSocket::~ServeurSocket()
{}

int		ServeurSocket::create(int)
{
  _sock = socket(AF_INET, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sin);
  _crecsize = sizeof(_csin);
  if (_sock != INVALID_SOCKET)
    {
      std::cout << "The socket " << _sock << " is now opened in TCP/IP" << std::endl;
      _sin.sin_addr.s_addr = inet_addr("127.0.0.1");  /* Adresse IP automatique */
      _sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
      _sin.sin_port = 17030;               /* Listage du port */
      _sock_err = bind(_sock, (sockaddr*)&_sin, _recsize);
      if (_sock_err != SOCKET_ERROR)
	{
	  // 5 is the number max of connection
	  _sock_err = listen(_sock, 5);
	  std::cout << "Listing the port " << PORT << "..." << std::endl;
	  if (_sock_err != SOCKET_ERROR)
	    {
	      std::cout << "Please wait during the client's connection to the port " << PORT << "..." << std::endl;
	      _csock = accept(_sock, (sockaddr*)&_csin, &_crecsize);
	      std::cout << "A client is connecting with the socket " << _csock << " of " <<
		inet_ntoa(_csin.sin_addr) << ":" << htons(_csin.sin_port) << std::endl;
	    }
	  else
	    throw CommunicationError("Error: listen error.");
	}
      else
	throw CommunicationError("Error: bind error.");
    }
  else
    throw CommunicationError("Error: socket error.");
  return (0);
}

int		ServeurSocket::destroy() const
{
  closesocket(_csock);
  closesocket(_sock);
  return (0);
}

int		ServeurSocket::read(t_processState &state) const
{
  if (::read(_csock, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
int		ServeurSocket::write(t_processState &state) const
{
  if (::write(_csock, &state, sizeof(state)) == -1)
    return (-1);
  return (0);
}
