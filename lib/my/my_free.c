/*
** my_free.c for free in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 21:30:28 2016 virgile junique
** Last update Sun Jun  5 21:13:40 2016 virgile junique
*/

#include "my.h"

void	my_free_ctab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	my_free_itab(int **tab)
{
  int	i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
}
