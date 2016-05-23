/*
** my_strncmp.c for my_strncmp in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 21:10:43 2016 virgile junique
** Last update Mon May 23 21:12:12 2016 virgile junique
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  int   j;

  i = 0;
  while (s1[i] == s2[i])
    i++;
  if ((n - 1) >= i)
    j = s1[i] - s2[i];
  else
    return (0);
  return (j);
}
