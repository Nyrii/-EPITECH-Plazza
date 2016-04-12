//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Wed Apr  6 13:33:00 2016 Florian Saurs
// Last update Tue Apr 12 16:58:43 2016 Saursinet
//

#ifndef SOCKET_HPP_
# define SOCKET_HPP_

# include <errno.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <sys/un.h>

# include "ICommunication.hpp"

# define INVALID_SOCKET -1
# define SOCKET_ERROR -1
# define closesocket(s) close (s)
# define PORT 8080

class	ASocket : public ICommunication
{
protected:
  int			_erreur;
  int			_sock;
  socklen_t		_recsize;
  int			_csock;
  socklen_t		_crecsize;
  int			_sock_err;

  sockaddr_in		_sin;
  sockaddr_in		_csin;

  sockaddr_un		_sun;
  sockaddr_un		_csun;

  std::string		_path;

public:
  virtual		~ASocket() {};
  virtual int		create(int) = 0;
  virtual int		destroy() const = 0;
  virtual int		read(t_processState &) const = 0;
  virtual int		write(t_processState &) const = 0;
};

#endif /* !SOCKET_HPP_ */
