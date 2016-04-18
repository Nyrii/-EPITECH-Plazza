//
// MainServeur.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 23:31:50 2016 Florian Saurs
// Last update Mon Apr 18 16:49:36 2016 Florian Saurs
//

#include "../inc/SocketsLocal.hpp"

int	main()
{
  int	pid = 0;
  Com *toto = new SocketsLocal(pid);
  char c;

  pid = fork();
  if (pid == 0)
    {
      c = 'a';
      toto->write(c);
      toto->read(c);
      std::cout << "received char in son ->" << c << std::endl;
      toto->write(++c);
      toto->read(c);
      std::cout << "received char in son ->" << c << std::endl;
      toto->write(++c);
      exit (0);
    }
  std::cout << "read = " << toto->read(c) << std::endl;;
  std::cout << "received char in main ->" << c << std::endl;
  toto->write(++c);
  std::cout << "read = " << toto->read(c) << std::endl;;
  std::cout << "received char in main ->" << c << std::endl;
  toto->write(++c);
  std::cout << "read = " << toto->read(c) << std::endl;;
  std::cout << "received char in main ->" << c << std::endl;
}
