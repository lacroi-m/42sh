/*
** gnl.c for  in /home/oudin_c/rendu/gnl
**
** Made by coudin
** Login   <oudin_c@epitech.net>
**
** Started on  Tue May 31 11:40:53 2016 coudin
** Last update Thu Jun  2 15:53:22 2016 coudin
*/

#include "gnl.h"

char		*buff_to_char(t_l *l)
{
  int		str_pos;
  char		*next_line;

  str_pos = 0;
  next_line = malloc(sizeof(char) * (l->n_line + 1));
  l->n_line += l->pos;
  while (l->curr && l->pos < l->n_line)
    {
      if (l->pos != l->curr->c)
	next_line[str_pos] = l->curr->buff[l->pos];
      else
	{
	  l->curr = l->curr->next;
	  l->n_line -= l->pos;
	  l->pos = -1;
	  str_pos--;
	}
      l->pos++;
      str_pos++;
    }
  next_line[str_pos] = '\0';
  return (next_line);
}

int		mode_gnl(t_l *l, int mode)
{
  static int	ini_pos = -1;
  static t_buf	*ini_curr;

  if (mode == -1)
    {
      if (ini_pos == -1)
      	{
      	  ini_pos = l->pos;
      	  ini_curr = l->curr;
      	  l->pos = 0;
      	  l->curr = l->start;
      	}
      else if (ini_pos == l->pos && l->curr == ini_curr)
      	{
	  ini_pos = -1;
	  return (1);
	}
    }
  else if (mode == -2)
    {
      free_buff(l);
      return (1);
    }
  return (0);
}

char		*gnl(int fd)
{
  static t_l	l;

  if (mode_gnl(&l, fd))
    return (NULL);
  if (!l.start)
    init(&l);
  while ((l.n_line = find_nl(l.curr, l.pos)) == -1)
    fil_buff(&l, fd);
  return (buff_to_char(&l));
}
