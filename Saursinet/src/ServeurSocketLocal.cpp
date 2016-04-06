//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Wed Apr  6 17:29:03 2016 Florian Saurs
//

#include <iostream>
#include "../inc/ServeurSocketLocal.hpp"

ServeurSocketLocal::ServeurSocketLocal()
{}

ServeurSocketLocal::~ServeurSocketLocal()
{}

int		ServeurSocketLocal::create()
{
  unlink("server_socket");
  _sock = socket(AF_UNIX, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sun);
  _crecsize = sizeof(_csun);
  if (_sock != INVALID_SOCKET)
    {
      std::cout << "La socket " << _sock <<
	" est maintenant ouverte en mode TCP/IP" << std::endl;
      struct sockaddr_un saddr = {AF_UNIX, "server_socket"};
      _sun = saddr;
      _sock_err = bind(_sock, (sockaddr*)&_sun, _recsize);
      if (_sock_err == SOCKET_ERROR)
	std::cerr << "Bind error" << std::endl;
    }
  else
    std::cerr << "Socket error" << std::endl;
  return (0);
}

int		ServeurSocketLocal::destroy()
{
  std::cout << "Fermeture de la socket client" << std::endl;
  closesocket(_csock);
  std::cout << "Fermeture de la socket serveur" << std::endl;
  closesocket(_sock);
  return (0);
}

std::string	ServeurSocketLocal::read()
{
  return ("");
}

int		ServeurSocketLocal::write(std::string const &)
{
  if (_sock_err != SOCKET_ERROR)
    {
      // 5 is the number max of connection
      _sock_err = listen(_sock, 5);
      if (_sock_err != SOCKET_ERROR)
	{
	  while (1)
	    {
	      char ch;
	      std::cout << "Server wait..." << std::endl;
	      _csock = accept(_sock, (sockaddr*)&_csun, &_crecsize);
	      ::read(_csock, &ch, 1);
	      ch++;
	      ::write(_csock, &ch, 1);
	      close(_csock);
	    }
	}
      else
	std::cerr << "Listen error" << std::endl;
    }
  return (0);
}
