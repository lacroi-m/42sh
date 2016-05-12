/*
** path.c for path in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Tue May 10 17:00:02 2016 virgile junique
** Last update Tue May 10 17:02:01 2016 virgile junique
*/

#include "my.h"

void    count_word(char *str, int *nb)
{
  int   i;

  i = 0;
  *nb = 1;
  while (str[i])
    {
      if (str[i] == ':')
        *nb = *nb + 1;
      i = i + 1;
    }
}

char    *check_slash(char *str)
{
  int   i;
  char  *dest;

  i = my_strlen(str);
  if (str[i - 1] != '/')
    {
      dest = xmalloc(sizeof(char) * (i + 2));
      i = 0;
      while (str[i] != '\0')
        dest[i] = str[i++];
      dest[i++] = '/';
      dest[i] = '\0';
      free(str);
      return (dest);
    }
  else
    return (str);
}

int     len_word(char *str, int num)
{
  int   i;
  int   j;
  int   len;

  i = 0;
  j = 1;
  len = 0;
  while (str[i] != '\0')
    {
      if (j == num)
        {
          while (str[i] != '\0' && str[i] != ':')
            {
              len = len + 1;
              i = i + 1;
            }
          return (len);
        }
      if (str[i] == ':')
        j = j + 1;
      else
        str[i] == '\0';
      i = i + 1;
    }
  return (-1);
}
