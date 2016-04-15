//
// Parsing.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 00:10:35 2016 Florian Saurs
// Last update Fri Apr 15 16:28:22 2016 guillaume wilmot
//

#ifndef SEARCH_HPP_
# define SEARCH_HPP_

# include <vector>
# include <string>
# include <boost/regex.hpp>
# include "Information.hh"
# include "Core.hpp"

class	Search
{
  boost::regex	*_reg;
  int		_nbReg;

public:
  Search();
  ~Search();

  std::vector<std::string>	parseFile(std::string, Information) const;
  std::string			searchInCurrent(std::string, Information) const;
  std::string			compareToReg(std::string) const;
};

#endif /* !SEARCH_HPP_ */
