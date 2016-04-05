//
// Parsing.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:35 2016 Florian Saurs
// Last update Tue Apr  5 02:16:25 2016 Florian Saurs
//

#ifndef PARSING_HPP_
# define PARSING_HPP_

# include <string>
# include <boost/regex.hpp>

class	Parsing
{
  boost::regex	*_reg;
  int		_nbReg;

public:
  Parsing();
  ~Parsing();

  void		parseFile(std::string) const;
  std::string	searchInCurrent(std::string) const;
  std::string	compareToReg(std::string) const;
};

#endif /* !PARSING_HPP_ */
