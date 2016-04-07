//
// namedPipe.hh for namedPipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:18:42 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 20:47:45 2016 guillaume wilmot
//

#ifndef NAMEDPIPE_HH_
# define NAMEDPIPE_HH_

# include <map>
# include <vector>

#include <unistd.h>
#include <fcntl.h>

# include "ICommunication.hpp"

class					namedPipe : public ICommunication
{
public:
  namedPipe();
  ~namedPipe();
  namedPipe(namedPipe const &);
  namedPipe				&operator=(namedPipe const &);

  int					create(int);
  int					destroy() const;
  std::string				read() const;
  int					write(std::string const &) const;

  int					getId() const;

  template <typename T>
  void					read2(T &buf) const
  {
    std::ifstream			readFile(std::string("./np") + std::to_string(_id), std::ifstream::in);

    if (!readFile.is_open())
      {
        std::cerr << "Error: opening of a named pipe failed." << std::endl;
        return ;
      }
    readFile.read(reinterpret_cast<char *>(&buf), sizeof(T));
    readFile.close();
  }


  private:
  int					_id;
  std::string				_path;
};

std::ostream				&operator<<(std::ostream &, namedPipe const &);
std::string const			&operator>>(std::string const &command, namedPipe const &namedPipe);

#endif /* !NAMEDPIPE_HH_ */
