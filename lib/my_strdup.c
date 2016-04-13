/*
** my_strdup.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:25:20 2016 Mehdi Meridja
** Last update Tue Apr 12 11:31:06 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "my.h"

char    *my_strdup(char *str)
{
  int   i;
  char  *new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != 0)
    {
      new[i] = str[i];
      i++;
    }
  new[i] = '\0';
  return (new);
}
