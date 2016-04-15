//
// Timer.hh for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr 15 22:43:51 2016 guillaume wilmot
// Last update Fri Apr 15 22:53:26 2016 guillaume wilmot
//

#ifndef TIMER_HH_
# define TIMER_HH_

class	Timer {
public:
  Timer() {}
  ~Timer() {}

  void		setTime(int);
  bool		isElapsed();
private:
  clock_t	_tick;
  int		_time;
};

#endif /* !TIMER_HH_ */
