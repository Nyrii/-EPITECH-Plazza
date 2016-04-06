//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Wed Apr  6 13:28:29 2016 Florian Saurs
//

#ifndef CLIENTSOCKET_HPP_
# define CLIENTSOCKET_HPP_

# include <sys/socket.h>
# include <sys/un.h>

# include <errno.h>
# include <netdb.h>
# include <string.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define closesocket(s) close (s)

# define PORT 8080

typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;

class	ClientSocket
{
  int		_erreur;
  SOCKADDR_IN	_sin;
  SOCKET	_sock;
  socklen_t	_recsize;

  SOCKADDR_IN	_csin;
  SOCKET	_csock;
  socklen_t	_crecsize;
  int		_sock_err;

public:
  ClientSocket();
  ~ClientSocket();

  int	run();
};

#endif /* !CLIENTSOCKET_HPP_ */
