/*
** my_realloc.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:36:31 2016 Mehdi Meridja
** Last update Tue Mar 29 13:36:33 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "my.h"

char	*my_realloc(char *str, int n)
{
  int	i;
  char	*new_str;

  i = 0;
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + n))) == NULL)
    return (NULL);
  while (str[i] != 0)
    {
      new_str[i] = str[i];
      i++;
    }
  free(str);
  return (new_str);
}
