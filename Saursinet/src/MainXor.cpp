//
// MainXor.cpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Thu Apr  7 00:23:08 2016 Florian Saurs
// Last update Fri Apr  8 23:44:38 2016 Florian Saurs
//

#include <fstream>
#include "../inc/CryptXor.hpp"

int	main()
{
  std::ifstream	file("xor", std::ifstream::in);

  std::string content( (std::istreambuf_iterator<char>(file) ),
                       (std::istreambuf_iterator<char>()    ) );

  CryptXor	cry;
  uint16_t	i = 0;
  int		start = 0;

  while (i != 0 || start == 0)
    {
      start = 1;
      std::cout << cry.decrypt(i++, content) << std::endl;
    }
}
