/*
** free.c for free in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sun Jun  5 17:35:01 2016 virgile junique
** Last update Sun Jun  5 17:37:34 2016 virgile junique
*/

#include "my.h"

void	my_free_3tab(char ***tab)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tab[i])
    {
      while (tab[i][j])
	{
	  free(tab[i][j]);
	  j++;
	}
      free(tab[i]);
      i++;
    }
  free(tab);
}
