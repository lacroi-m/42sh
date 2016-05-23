/*
** my_str_to_wordtab.c for my_str_to_wordtab.c in /home/da-sil_t/rendu/test
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Fri Jan 22 16:52:21 2016 theo da-silva
** Last update Mon May 23 21:04:07 2016 virgile junique
*/

#include "my.h"

int	my_nb_word(char *str)
{
  int	i;
  int	r;

  i = 0;
  r = 0;
  while (str[i] != '\0')
    {
      while (str[i] <= 32 && str[i] != '\0')
	i++;
      if (str[i] != '\0')
	{
	  if (str[i] > 32)
	    {
	      r++;
	      while (str[i] > 32&& str[i] != '\0')
		i++;
	    }
	}
    }
  return (r);
}

char	**my_str_to_wordtab(char *str)
{
  char  **r;
  int   i;
  int   u;
  int   j;

  i = 0;
  u = 0;
  j = 0;
  if ((r = malloc((my_nb_word(str) + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      while (str[i] <= 32 && str[i] != '\0')
        i++;
      u = i;
      while (str[u] > 32 && str[u] != '\0')
        u++;
      if (str[i] != '\0')
        r[j++] = my_strndup(&str[i], u - i);
      i = (str[u] != 0) ? u + 1 : u;
    }
  r[j] = NULL;
  return (r);
}
