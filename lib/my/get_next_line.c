/*
** get_next_line.c for get_next_line in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Mon May  2 11:23:39 2016 virgile junique
** Last update Mon May  2 12:39:55 2016 virgile junique
*/

#include "my.h"
#include "get_next_line.h"

char		*my_reader(const int fd, char **save)
{
  char		buff[READ_SIZE + 1];
  char		*line;
  int		i;
  int		size;

  while ((size = read(fd, buff, READ_SIZE)) > 0)
    {
      buff[size] = '\0';
      i = 0;
      while (i < size)
	{
	  if (buff[i] == '\0' || buff[i] == '\n')
	    {
	      line = my_strncat(*save, buff, i);
	      *save = my_strndup(buff + i + 1, my_strlen(buff + i + 1));
	      return (line);
	    }
	  ++i;
	}
      *save = my_strncat(*save, buff, my_strlen(buff));
    }
  return (NULL);
}

char		*get_next_line(const int fd)
{
  static char	*save;
  char		*line1;
  char		*line2;
  char		*tmp;
  int		i;

  i = 0;
  if (save != NULL)
    {
      while (save[i] != '\0')
	{
	  if (save[i] == '\n')
	    {
	      tmp = save;
	      line2 = my_strndup(save, i);
	      save = my_strndup(save + i + 1, my_strlen(save + i + 1));
	      free(tmp);
	      return (line2);
	    }
	  ++i;
	}
    }
  line1 = my_reader(fd, &save);
  return (line1);
}
