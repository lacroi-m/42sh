/*
** get_next_line.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:39:21 2016 Mehdi Meridja
** Last update Tue Apr 12 11:04:27 2016 Mehdi Meridja
*/

#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"
#include "my.h"

char		get_to_ch(int fd)
{
  static t_line	line;

  if (line.size == 0)
    {
      if ((line.size = read(fd, line.buffer, READ_SIZE)) == -1)
	return (-1);
      if (line.size == 0)
	return (0);
      line.buff = (char*)&line.buffer;
    }
  line.ch = *line.buff;
  line.size--;
  line.buff++;
  return (line.ch);
}

char	*get_line(int fd)
{
  t_get	get;

  get.line = malloc_x(READ_SIZE + 1);
  if ((get.ch = get_to_ch(fd)) == -1)
    return (NULL);
  get.size = 0;
  while (get.ch != '\0' && get.ch != '\n')
    {
      get.line[get.size] = get.ch;
      get.ch = get_to_ch(fd);
      if (++get.size % (READ_SIZE + 1) == 0)
	get.line = my_realloc(get.line, get.size + READ_SIZE + 1);
    }
  get.line[get.size] = '\0';
  if (get.line[0] == 0 && get.ch == 0)
    return (NULL);
  return (get.line);
}
