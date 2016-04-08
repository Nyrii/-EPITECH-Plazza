//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Fri Apr  8 11:10:40 2016 Florian Saurs
//

#include <iostream>
#include "../inc/ServeurSocket.hpp"

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
      std::cout << "La socket " << _sock << " est maintenant ouverte en mode TCP/IP" << std::endl;
      _sin.sin_addr.s_addr = inet_addr("127.0.0.1");  /* Adresse IP automatique */
      _sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
      _sin.sin_port = 17030;               /* Listage du port */
      _sock_err = bind(_sock, (sockaddr*)&_sin, _recsize);
      if (_sock_err != SOCKET_ERROR)
	{
	  // 5 is the number max of connection
	  _sock_err = listen(_sock, 5);
	  std::cout << "Listage du port " << PORT << "..." << std::endl;
	  if (_sock_err != SOCKET_ERROR)
	    {
	      std::cout << "Patientez pendant que le client se connecte sur le port " << PORT << "..." << std::endl;
	      _csock = accept(_sock, (sockaddr*)&_csin, &_crecsize);
	      std::cout << "Un client se connecte avec la socket " << _csock << " de " <<
		inet_ntoa(_csin.sin_addr) << ":" << htons(_csin.sin_port) << std::endl;
	    }
	  else
	    std::cerr << "Listen" << std::endl;
	}
      else
	std::cerr << "Bind" << std::endl;
    }
  else
    std::cerr << "Socket" << std::endl;
  return (0);
}

int		ServeurSocket::destroy() const
{
  std::cout << "Fermeture de la socket client" << std::endl;
  closesocket(_csock);
  std::cout << "Fermeture de la socket serveur" << std::endl;
  closesocket(_sock);
  return (0);
}

void		ServeurSocket::read(t_processState &) const
{}

void		ServeurSocket::write(t_processState &tmp) const
{
  int		err;

  err = send(_csock, &tmp, sizeof(tmp), 0);
  if(err != SOCKET_ERROR)
    std::cout << "Chaine envoyée : " << std::endl;
  else
    std::cout << "Erreur de transmission" << std::endl;
  shutdown(_csock, 2);
}
