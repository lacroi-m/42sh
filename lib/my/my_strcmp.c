/*
** my_strcmp.c for my_strcmp in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh
**
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
**
** Started on  Mon May 23 15:22:26 2016 theo da-silva
** Last update Mon May 23 23:15:30 2016 virgile junique
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != '\0')
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
	return (1);
      i = i + 1;
    }
  return (0);
}
