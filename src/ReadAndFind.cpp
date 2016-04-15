//
// ReadAndFind.cpp for ReadAndFind in /Users/noboud_n/rendu/cpp_plazza/src/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Wed Apr 13 14:27:40 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr 15 18:51:33 2016 guillaume wilmot
//

#include <fstream>
#include <iostream>
#include "CryptCaesar.hh"
#include "CryptXor.hpp"
#include "Search.hpp"
#include "ReadAndFind.hh"

ReadAndFind::ReadAndFind() {}

ReadAndFind::~ReadAndFind() {}

void				*ReadAndFind::execute(void *// arg
						      )
// void				ReadAndFind::execute(std::string fileName, type _type) const
{
  // Search			search;
  // CryptXor			Xor;
  // CryptCaesar			Caesar;
  // std::vector<std::string>	found;
  // uint16_t			i = 0;
  // int				start = 0;
  // std::ifstream			file(fileName.c_str(), std::ifstream::in);
  // std::string			content((std::istreambuf_iterator<char>(file)),
  // 					(std::istreambuf_iterator<char>()));

  // found = search.parseFile(content, _type);
  // while (found.size() == 0)
  //   {
  //     while ((i != 0 || start == 0) && found.size() == 0)
  // 	{
  // 	  start = 1;
  // 	  found = search.parseFile(Xor.Decrypt(content, 0, i++), _type);
  // 	}
  //     start = 0;
  //     while (start <= 255 && found.size() == 0)
  // 	found = search.parseFile(Caesar.Decrypt(content, start++, 0), _type);
  //   }
  // for (std::vector<std::string>::iterator it = found.begin(); it != found.end(); ++it)
  //   std::cout << *it << std::endl;
  // file.close();
  std::cout << "Struct a creer dans Readandfind" << std::endl;
  return (NULL);
}
