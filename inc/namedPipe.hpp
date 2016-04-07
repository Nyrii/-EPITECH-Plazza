//
// namedPipe.hh for namedPipe in /Users/noboud_n/rendu/cpp_plazza/nyrii/
//
// Made by Nyrandone Noboud-Inpeng
// Login   <noboud_n@epitech.eu>
//
// Started on  Tue Apr  5 21:18:42 2016 Nyrandone Noboud-Inpeng
// Last update Thu Apr  7 23:24:35 2016 Nyrandone Noboud-Inpeng
//

#ifndef NAMEDPIPE_HH_
# define NAMEDPIPE_HH_

# include <map>
# include <vector>

# include <unistd.h>
# include <fcntl.h>

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
  template <typename S>
  int					write2(S &buf) const
  {
      std::fstream			writeFile(std::string("./np") + std::to_string(_id), std::fstream::out);

      if (!writeFile.is_open())
	{
	  std::cerr << "Error: opening of a named pipe to write in it failed." << std::endl;
	  return (-1);
	}
      writeFile.write(reinterpret_cast<char *>(&buf), sizeof(S));
      writeFile.close();
      return (0);
  }

  int					getId() const;

  template <typename T>
  int					read2(T &buf) const
    {
      std::fstream			readFile(std::string("./np") + std::to_string(_id), std::fstream::in);

      if (!readFile.is_open())
	{
	  std::cerr << "Error: opening of a named pipe to read in it failed." << std::endl;
	  return (-1);
	}
      readFile.read(reinterpret_cast<char *>(&buf), sizeof(T));
      readFile.close();
      return (0);
    }


  private:
  int					_id;
  std::string				_path;
};

std::ostream				&operator<<(std::ostream &, namedPipe const &);
std::string const			&operator>>(std::string const &command, namedPipe const &namedPipe);

#endif /* !NAMEDPIPE_HH_ */
