//
// Core.hpp for  in /home/saurs_f/cpp_plazza/Saursinet
//
// Made by Florian Saurs
// Login   <saurs_f@epitech.net>
//
// Started on  Tue Apr  5 16:57:11 2016 Florian Saurs
// Last update Tue Apr 19 18:04:31 2016 Saursinet
//

#ifndef CORE_HPP_
# define CORE_HPP_

# include <vector>
# include "Process.hpp"
# include "Queue.hpp"

enum	Communication
  {
    LOCAL_SOCKET,
    INTERNET_SOCKET,
    NAMED_PIPE
  };

class	Core
{
  std::vector<Process *>	_sonTab;
  std::map<Communication, void (Core:: *)(int &)>	_communicationTab;
  bool				_isFinished;
  int				_nbThreads;
  Com				*_com;

public:
  Core(int);
  ~Core();

  void	runProcess(std::string, Information, Communication);
  void	createPipes(int &);
  void	createSockets(int &);
  void	createSocketsLocal(int &);
  int	checkAvailable() const;
  void	read(Communication) const;

  void				setSonTab(std::vector<Process *> *);
  static std::vector<Process *>	*getSonTab(std::vector<Process *> *);
  static void			sigHandler(int);
};

#endif /* !CORE_HPP_ */
