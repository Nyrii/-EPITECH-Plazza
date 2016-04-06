//
// MainServeur.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 23:31:50 2016 Florian Saurs
// Last update Wed Apr  6 14:47:34 2016 Florian Saurs
//

#include "../inc/ClientSocket.hpp"

int	main()
{
  ClientSocket	sock;

  sock.create();
  sock.read();
  sock.destroy();
}
