/*
** test_system.c for test_system in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 21:17:57 2016 virgile junique
** Last update Sun Jun  5 15:48:47 2016 virgile junique
*/

#include "my.h"

int	xopen(const char *pathname, int flag)
{
  int	fd;

  fd = open(pathname, flag);
  if (fd == -1)
    {
      my_putstr("File does not exist.\n", 2, -1);
      exit(1);
    }
  return (fd);
}

void	xclose(int fd)
{
  if (close(fd) == -1)
    {
      my_putstr("Close Error\n", 2, -1);
      exit(1);
    }
}

void	*xmemset(char *str)
{
  int	i;

  i = 0;
  while (i != my_strlen(str))
    {
      str[i] = '\0';
      i++;
    }
  return (str);
}

void	*xmalloc(int size)
{
  void	*str;

  str = malloc(size);
  if (str == NULL)
    {
      my_putstr("Malloc error.\n", 2, -1);
      return ;
    }
  return (str);
}
