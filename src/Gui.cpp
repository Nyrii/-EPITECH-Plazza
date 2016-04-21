//
// Gui.cpp for Plazza in /home/wilmot_g/Rendu/cpp_plazza
//
// Made by guillaume wilmot
// Login   <wilmot_g@epitech.net>
//
// Started on  Sun Apr 17 19:59:02 2016 guillaume wilmot
// Last update Thu Apr 21 20:18:41 2016 Florian Saurs
//

#include <cstring>
#include <ncurses/curses.h>
#include <signal.h>
#include <algorithm>
#include <unistd.h>
#include <signal.h>
#include "Gui.hpp"
#include "Thread.hpp"
#include "Core.hpp"
#include "Parsing.hpp"



Gui::Gui()
{
  _menuFiles = NULL;
}

Gui::~Gui()
{
  endwin();
  if (_menuFiles)
    delete _menuFiles;
}

void				Gui::handleResize()
{
  endwin();
  refresh();
  clear();
}

void				Gui::init(Core *core)
{
  _core = core;
  _menuFiles = new MenuFiles(core);
  _menuTasks = new MenuTasks(core);
  initscr();
  start_color();
  timeout(1000);
  noecho();
  curs_set(0);
  init_pair(1, COLOR_BLACK, COLOR_CYAN);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_BLACK, COLOR_CYAN);
}

void				Gui::changeDir(std::string &path, DIR **dir)
{
  if (chdir(path.c_str()) == -1)
    return;
  path = "./";
  if ((*dir = opendir(path.c_str())) == NULL)
    {
      std::cerr << "Cannot open folder" << std::endl;
      return ;
    }
}

void				Gui::startMenu(Communication com)
{
  std::vector<std::string>	choices;
  DIR                           *dir = NULL;
  struct dirent                 *rd;
  int				ret;
  std::string			path = "./";

  while (1)
    {
      changeDir(path, &dir);
      while ((rd = readdir(dir)) != NULL)
	{
	  if ((std::string(rd->d_name).at(0) != 'n' || std::string(rd->d_name).at(1) != 'p') && std::string(rd->d_name) != ".")
	  choices.push_back(std::string(rd->d_name));
	}
      std::sort(choices.begin(), choices.end());
      closedir(dir);
      if (_menuFiles->init(choices) == -1 ||
	  _menuFiles->initWindow() == -1)
	return ;
      _menuFiles->draw();
      if ((ret = _menuFiles->events()) == -1)
	return ;
      if (ret == 1)
	path = reinterpret_cast<MenuFiles *>(_menuFiles)->getDir();
      else if (ret != 2)
	{
	  if (_menuTasks->init(choices) == -1 ||
	      _menuTasks->initWindow() == -1)
	    return ;
	  _menuTasks->draw();
	  if ((ret = _menuTasks->events()) == 0)
	    {
	      _order += _menuFiles->getRet() + _menuTasks->getRet();
	      Parsing			parser;
	      std::vector<std::string>	command;
	      command.push_back(_order);
	      parser.parseCommandLine(&command, _core, com);
	      _order.clear();
	    }
	}
      _menuFiles->free();
      choices.clear();
    }
}
