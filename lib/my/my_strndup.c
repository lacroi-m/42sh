/*
** my_strndup.c for strndup in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Mon May  2 11:25:57 2016 virgile junique
** Last update Mon May  2 12:37:15 2016 virgile junique
*/

#include "my.h"

char	*my_strndup(char *src, int n)
{
  char	*dest;
  int	i;

  i = 0;
  if (!(dest = malloc(sizeof(char) * (n + 1))) || !src)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
