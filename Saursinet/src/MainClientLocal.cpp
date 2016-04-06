//
// MainServeur.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 23:31:50 2016 Florian Saurs
// Last update Wed Apr  6 16:04:27 2016 Florian Saurs
//

#include "../inc/ClientSocketLocal.hpp"

int	main()
{
  ClientSocketLocal	sock;

  sock.create();
  sock.read();
  sock.destroy();
}
