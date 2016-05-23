/*
** my_strncpy.c for my_strncpy in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 22:38:48 2016 virgile junique
** Last update Mon May 23 22:59:15 2016 virgile junique
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	len;

  i = 0;
  len = my_strlen(src);
  while (i < n)
    {
      dest[i] = src[i];
      i++;
    }
  if (n > len)
    dest[len] = '\0';
  return (dest);
}
