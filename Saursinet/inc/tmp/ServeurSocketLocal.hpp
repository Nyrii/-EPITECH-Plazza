//
// Socket.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 22:24:35 2016 Florian Saurs
// Last update Wed Apr  6 15:58:00 2016 Florian Saurs
//

#ifndef SERVEURSOCKETLOCAL_HPP_
# define SERVEURSOCKETLOCAL_HPP_

# include "ASocket.hpp"

class	ServeurSocketLocal : public ASocket
{
public:
  ServeurSocketLocal();
  virtual	~ServeurSocketLocal();

  int		create();
  int		destroy();
  std::string	read();
  int		write(std::string const &);
};

#endif /* !SERVEURSOCKETLOCAL_HPP_ */
