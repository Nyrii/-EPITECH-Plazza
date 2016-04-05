//
// Socket.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:25:27 2016 Florian Saurs
// Last update Tue Apr  5 23:34:34 2016 Florian Saurs
//

#include <iostream>
#include "../inc/ServeurSocket.hpp"

ServeurSocket::ServeurSocket()
{
  _sock = socket(AF_INET, SOCK_STREAM, 0);
  _erreur = 0;
  _recsize = sizeof(_sin);
  _crecsize = sizeof(_csin);
}

ServeurSocket::~ServeurSocket()
{}

int	ServeurSocket::run()
{
  if (_sock != INVALID_SOCKET)
    {
      std::cout << "La socket " << _sock << " est maintenant ouverte en mode TCP/IP" << std::endl;
      _sin.sin_addr.s_addr = htonl(INADDR_ANY);  /* Adresse IP automatique */
      _sin.sin_family = AF_INET;                 /* Protocole familial (IP) */
      _sin.sin_port = htons(PORT);               /* Listage du port */
      _sock_err = bind(_sock, (SOCKADDR*)&_sin, _recsize);
      if (_sock_err != SOCKET_ERROR)
	{
	  _sock_err = listen(_sock, 5);
	  std::cout << "Listage du port " << PORT << "..." << std::endl;
	  if (_sock_err != SOCKET_ERROR)
	    {
	      std::cout << "Patientez pendant que le client se connecte sur le port " << PORT << "..." << std::endl;
	      _csock = accept(_sock, (SOCKADDR*)&_csin, &_crecsize);
	      std::cout << "Un client se connecte avec la socket " << _csock << " de " <<
		inet_ntoa(_csin.sin_addr) << ":" << htons(_csin.sin_port) << std::endl;
	    }
	  else
	    perror("listen");
	}
      else
	perror("bind");
      std::cout << "Fermeture de la socket client" << std::endl;
      closesocket(_csock);
      std::cout << "Fermeture de la socket serveur" << std::endl;
      closesocket(_sock);
    }
  else
    perror("socket");
  return (EXIT_SUCCESS);
}
