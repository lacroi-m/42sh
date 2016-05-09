/*
** wordtab_custom.c for wordtab in /home/meridj/Rendu/PSU_2015_42sh/lib/my/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Fri May  6 14:14:12 2016 Mehdi Meridja
** Last update Mon May  9 10:00:24 2016 Mehdi
*/

#include "my.h"

static int     cpt_words(char *str)
{
  int		i;
  int		cpt;

  i = 0;
  cpt = 0;
  while (str[i] != '\0')
    {
      if (str[i] != 0 && str[i] != '\t' && str[i] != ' ')
	{
          cpt++;
          while (str[i] != 0 && str[i] != '\t' && str[i] != ' ')
            i++;
	}
      if (str[i] != 0)
        i++;
    }
  return (cpt);
}

char    **wordtab_custom(char *str)
{
  int   i;
  int   j;
  int   deb;
  char  **tab;

  j = 0;
  i = 0;
  deb = 0;
  if ((tab = malloc(sizeof(char *) * (cpt_words(str) + 1))) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      if (str[i] != 0 && str[i] != ' ' && str[i] != '\t')
        {
          deb = i;
          while (str[i] != 0 && str[i] != ' ' && str[i] != '\t')
            i++;
          tab[j++] = my_strndup(&str[deb], i - deb);
        }
      else
        i++;
    }
  tab[j] = NULL;
  return (tab);
}
