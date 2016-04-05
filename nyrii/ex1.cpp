/*
** ex1.c for lol in /Users/noboud_n/rendu/cpp_plazza/
**
** Made by Nyrandone Noboud-Inpeng
** Login   <noboud_n@epitech.eu>
**
** Started on  Mon Apr  4 20:18:09 2016 Nyrandone Noboud-Inpeng
** Last update Mon Apr  4 21:11:21 2016 Nyrandone Noboud-Inpeng
*/

#include <pthread.h>
#include <iostream>
#include <sstream>

void	*increment_counter(void *N)
{
  *(int *)N += 1;
  return (N);
}

int		main(int argc, char **argv)
{
  pthread_t	pth[50];
  int		return_value;
  int		i;
  int		nbThread;
  std::stringstream	os;

  if (argc != 2)
    return (-1);
  i = 0;
  os << argv[1];
  os >> nbThread;
  while (i < nbThread)
    pthread_create(&pth[i++], NULL, &increment_counter, &return_value);

  i = 0;
  while (i < nbThread)
    pthread_join(pth[i++], NULL);
  
  std::cout << return_value << std::endl;
  return (0);
}
