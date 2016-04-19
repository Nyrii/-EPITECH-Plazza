//
// MenuFiles.hpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Mon Apr 18 04:44:42 2016 guillaume wilmot
// Last update Tue Apr 19 15:46:39 2016 guillaume wilmot
//

#ifndef MENUFILES_HPP_
# define MENUFILES_HPP_

# include "Menu.hpp"

class		MenuFiles : public Menu {
public:
  MenuFiles();
  ~MenuFiles();

  int		init(const std::vector<std::string> &);
  int		initWindow();
  void		draw();
  void		free();
  int		events();
  void		setFiles();
  std::string	getDir() const;
  std::string	getRet();
  void		printThreads(int);
  void		printDirectory();
  void		printHelp(int);

private:
  ITEM		**_items;
  unsigned int	_nbItem;
  std::string	_ret;
  std::string	_dir;
};

#endif /* !MENU_FILES */
