/*
** my_strndup.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:24:37 2016 Mehdi Meridja
** Last update Tue Mar 29 13:24:40 2016 Mehdi Meridja
*/

#include <stdlib.h>
#include "my.h"

char    *my_strndup(char *str, int n)
{
  int   i;
  char  *new;

  if ((new = malloc(sizeof(char) * (n + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != 0 && i < n)
    {
      new[i] = str[i];
      i++;
    }
  new[i] = 0;
  return (new);
}
