/*
** my_str_to_wordtab.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:35:30 2016 Mehdi Meridja
** Last update Mon Apr 11 14:06:56 2016 Mehdi
*/

#include <stdlib.h>

#include "my.h"

int	cpt_words(char *str)
{
  int   i;
  int   cpt;

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

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	deb;
  char	**tab;

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
