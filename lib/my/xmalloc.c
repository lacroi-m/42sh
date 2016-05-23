/*
** xmalloc.c for xmalloc in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  9 15:52:06 2016 virgile junique
** Last update Mon May 23 15:52:07 2016 virgile junique
*/

#include "my.h"

void	*xmalloc(int size)
{
  void	*str;

  if ((str = malloc(size)) == NULL)
    {
      my_putstr("Malloc error.\n", 2, -1);
      return (NULL);
    }
  return (str);
}
