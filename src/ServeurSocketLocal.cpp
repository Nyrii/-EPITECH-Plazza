//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Tue Apr 12 16:57:27 2016 Saursinet
//

#include <iostream>
#include "ServeurSocketLocal.hpp"
#include "Errors.hpp"

ServeurSocketLocal::ServeurSocketLocal()
{}

ServeurSocketLocal::~ServeurSocketLocal()
{
  unlink(_path.c_str());
}

int		ServeurSocketLocal::create(int _id)
{
  struct sockaddr_un saddr;

  _path = std::string("./soLoc") + std::to_string(_id);
  unlink(_path.c_str());
  _sock = socket(AF_UNIX, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sun);
  _crecsize = sizeof(_csun);
  if (_sock != INVALID_SOCKET)
    {
      std::cout << "La socket " << _sock <<
	" est maintenant ouverte en mode local" << std::endl;
      saddr.sun_family = AF_UNIX;
      strcpy(saddr.sun_path, _path.c_str());
      _sun = saddr;
      _sock_err = bind(_sock, (sockaddr*)&_sun, _recsize);
      if (_sock_err == SOCKET_ERROR)
	throw CommunicationError("Error: bind error.");
    }
  else
    throw CommunicationError("Error: socket error.");
  return (0);
}

int		ServeurSocketLocal::destroy() const
{
  std::cout << "Close of the client socket" << std::endl;
  closesocket(_csock);
  std::cout << "Close of the server socket" << std::endl;
  closesocket(_sock);
  return (0);
}

int		ServeurSocketLocal::read(t_processState &) const
{
  return (0);
}

int		ServeurSocketLocal::write(t_processState &) const
{
  int		err;

  if (_sock_err != SOCKET_ERROR)
    {
      // 5 is the number max of connection
      err = listen(_sock, 5);
      if (err != SOCKET_ERROR)
	{
	  while (1)
	    {
	      char ch;
	      std::cout << "Server wait..." << std::endl;
	      // _csock = accept(_sock, (sockaddr*)&_csun, &_crecsize);
	      ::read(_csock, &ch, 1);
	      ch++;
	      ::write(_csock, &ch, 1);
	      close(_csock);
	    }
	}
      else
	throw CommunicationError("Error: listen error");
    }
  return (0);
}
