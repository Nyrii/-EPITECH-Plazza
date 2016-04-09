//
// CryptCaesar.hh for CryptCaesar in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Thu Apr  7 10:31:54 2016 Nyrandone Noboud-Inpeng
// Last update Fri Apr  8 10:43:35 2016 Florian Saurs
//

#ifndef CRYPTCAESAR_HH_
# define CRYPTCAESAR_HH_

# include "ICrypt.hpp"

class			CryptCaesar : public ICrypt
{
public:
  CryptCaesar();
  ~CryptCaesar();

  std::string		Decrypt(std::string, int, uint16_t);
};

#endif /* !CRYPTCAESAR_HH_ */
