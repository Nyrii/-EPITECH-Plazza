//
// Term.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Tue Apr 19 18:51:03 2016 guillaume wilmot
// Last update Tue Apr 19 18:54:34 2016 guillaume wilmot
//

#include "Term.cpp"

Term::Term()
{
  tcgetattr(0, &_term);
}

Term::~Term()
{
  tcsetattr(0, TCSANOW, &_term);
}

struct termios		Term::getTerm() const
{
  return (_term);
}

void			Term::setNonBlocking()
{
  term = _term;;
  term.c_lflag &= ~ICANON;
  term.c_lflag &= ~ECHO;
  term.c_lflag &= ~ISIG;
  term.c_cc[VMIN] = 0;
  term.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &term);
  return(0);

}
