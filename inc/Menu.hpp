//
// Menu.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr 18 03:54:51 2016 guillaume wilmot
// Last update Tue Apr 19 15:16:46 2016 guillaume wilmot
//

#ifndef MENU_HPP_
# define MENU_HPP_

# include <ncurses/menu.h>
# include <vector>
# include <iostream>

class		Menu {
public:
  Menu() {_win = NULL; _subWin = NULL; _menu = NULL;}
  virtual		~Menu() {}

  virtual int		init(const std::vector<std::string> &) = 0;
  virtual int		initWindow() = 0;
  virtual void		draw() = 0;
  virtual void		free() = 0;
  virtual int		events() = 0;
  virtual std::string	getRet() = 0;
  void			unpost() {unpost_menu(_menu);}

protected:
  WINDOW	*_win;
  WINDOW	*_subWin;
  MENU		*_menu;
  std::string	result;
};

#endif /* !MENU_HPP_ */
