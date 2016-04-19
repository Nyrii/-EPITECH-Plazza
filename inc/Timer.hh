//
// Timer.hh for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Fri Apr 15 22:43:51 2016 guillaume wilmot
// Last update Tue Apr 19 17:54:55 2016 Florian Saurs
//

#ifndef TIMER_HH_
# define TIMER_HH_

class	Timer
{
public:
  Timer();
  ~Timer() {}

  void			setTime(int);
  bool			isElapsed();
private:
  timer_t		_id;
};

#endif /* !TIMER_HH_ */
