/*
** my_strdup.c for strdup in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May 23 21:13:52 2016 virgile junique
** Last update Mon May 23 21:15:03 2016 virgile junique
*/

#include "my.h"

char	*my_strdup(char *src)
{
  char  *copy;
  int   i;
  int   len;

  len = my_strlen(src);
  i = 0;
  if (src == NULL || (copy = malloc(len + 1)) == NULL)
    return (NULL);
  while (i < len)
    {
      copy[i] = src[i];
      i = i + 1;
    }
  copy[i] = '\0';
  return (copy);
}
