/*
** gnl0.c for  in /home/oudin_c/rendu/gnl
**
** Made by coudin
** Login   <oudin_c@epitech.net>
**
** Started on  Tue May 31 23:46:12 2016 coudin
** Last update Wed Jun  1 12:32:03 2016 coudin
*/

#include "gnl.h"

void		fil_buff(t_l *l, int fd)
{
  t_buf		*n_buff;

  if (l->end->c < BUFF_SIZE)
    l->end->c += read(fd, &l->end->buff[l->end->c], BUFF_SIZE - l->end->c);
  else
    {
      n_buff = malloc(sizeof(t_buf));
      n_buff->next = NULL;
      n_buff->c = 0;
      init_buff(n_buff);
      l->end->next = n_buff;
      l->end = n_buff;
      fil_buff(l, fd);
    }
}

int		find_nl(t_buf *buff, int pos)
{
  int		i;

  i = 0;
  if (pos == BUFF_SIZE)
    {
      pos = 0;
      buff = buff->next;
    }
  while (buff && buff->buff[pos] && buff->buff[pos] != '\n')
    {
      i++;
      pos++;
      if (pos == BUFF_SIZE)
	{
	  buff = buff->next;
	  pos = 0;
	}
    }
  if (!buff || buff->c == 0 || !buff->buff[pos])
    return (-1);
  else
    return (i + 1);
}

void		init_buff(t_buf *buff)
{
  int		i;

  i = 0;
  while (i != BUFF_SIZE)
    buff->buff[i++] = '\0';
}

void		free_buff(t_l *l)
{
  t_buf		*tmp;

  while (l->start)
    {
      tmp = l->start->next;
      free(l->start);
      l->start = tmp;
    }
  l->pos = 0;
}

void		init(t_l *l)
{
  l->start = malloc(sizeof(t_buf));
  l->start->c = 0;
  l->start->next = NULL;
  init_buff(l->start);
  l->curr = l->start;
  l->end = l->start;
  l->pos = 0;
  l->n_line = 0;
}
