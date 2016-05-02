/*
** my_strncat.c for strncat in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Mon May  2 11:25:09 2016 virgile junique
** Last update Mon May  2 12:36:49 2016 virgile junique
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int n)
{
  char	*str;
  int	len;
  int	i;

  i = 0;
  len = my_strlen(dest);
  if ((str = malloc(sizeof(char) * (len + n + 1))) == NULL)
    return (NULL);
  while (i < len + n)
    {
      str[i] = i < len ? dest[i] : src[i - len];
      ++i;
    }
  str[len + n] = '\0';
  free(dest);
  return (str);
}
