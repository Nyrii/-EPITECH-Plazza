//
// Timer.hh for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr 15 22:43:51 2016 guillaume wilmot
// Last update Sat Apr 16 20:07:19 2016 Nyrandone Noboud-Inpeng
//

#ifndef TIMER_HH_
# define TIMER_HH_

class	Timer {
public:
  Timer();
  ~Timer() {}

  void			setTime(int);
  bool			isElapsed();
private:
  timer_t		_id;
};

#endif /* !TIMER_HH_ */
