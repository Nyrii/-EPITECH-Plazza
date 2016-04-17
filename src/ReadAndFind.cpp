//
// ReadAndFind.cpp for ReadAndFind in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Wed Apr 13 14:27:40 2016 Nyrandone Noboud-Inpeng
// Last update Sun Apr 17 16:48:15 2016 guillaume wilmot
//

#include <fstream>
#include <iostream>
#include "CryptCaesar.hh"
#include "CryptXor.hpp"
#include "Search.hpp"
#include "ReadAndFind.hh"

ReadAndFind::ReadAndFind() {}

ReadAndFind::~ReadAndFind() {}

void				*ReadAndFind::execute(void *arg)
{
  t_args			*args;
  args = reinterpret_cast<t_args *>(arg);

  Search			search;
  CryptXor			Xor;
  CryptCaesar			Caesar;
  std::vector<std::string>	found;
  // uint16_t			i = 0;
  int				start = 0;
  std::ifstream			file(args->file.c_str(), std::ifstream::in);
  std::string			content((std::istreambuf_iterator<char>(file)),
  					(std::istreambuf_iterator<char>()));

  found = search.parseFile(content, args->order);
  // while ((i != 0 || start == 0) && found.size() == 0)
  //   {
  //     start = 1;
  //     std::cerr << "Debug " << i << std::endl;
  //     found = search.parseFile(Xor.Decrypt(content, 0, i++), args->order);
  //   }
  for (start = 0; start <= 255 && found.size() == 0; start++)
    found = search.parseFile(Caesar.Decrypt(content, start, 0), args->order);
  for (std::vector<std::string>::iterator it = found.begin(); it != found.end(); ++it)
    std::cout << *it << std::endl;
  file.close();
  return (NULL);
}
