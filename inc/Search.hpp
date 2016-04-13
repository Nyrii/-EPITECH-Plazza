//
// Parsing.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:35 2016 Florian Saurs
// Last update Fri Apr  8 23:57:24 2016 Florian Saurs
//

#ifndef SEARCH_HPP_
# define SEARCH_HPP_

# include <vector>
# include <string>
# include <boost/regex.hpp>
# include "Core.hpp"

class	Search
{
  boost::regex	*_reg;
  int		_nbReg;

public:
  Search();
  ~Search();

  std::vector<std::string>	parseFile(std::string, type) const;
  std::string			searchInCurrent(std::string, type) const;
  std::string			compareToReg(std::string) const;
};

#endif /* !SEARCH_HPP_ */
