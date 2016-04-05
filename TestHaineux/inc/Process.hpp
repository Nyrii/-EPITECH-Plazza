//
// Process.hpp for  in /home/wilmot_g/Rendu/cpp_plazza/TestHaineux
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr  5 16:29:21 2016 guillaume wilmot
// Last update Tue Apr  5 19:37:45 2016 guillaume wilmot
//

#ifndef PROCESS_HP_
# define PROCESS_HPP_

class		Process {
public:
  Process();
  ~Process() {}

  std::string	start();
  int		create(int, int);
private:
  int		_pid;
  int		_id;
};

#endif /* !PROCESS_HPP_ */
