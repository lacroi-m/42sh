/*
** my_strcpy.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:25:32 2016 Mehdi Meridja
** Last update Tue Apr 12 11:10:06 2016 Mehdi Meridja
*/

#include "my.h"

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = -1;
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (src[++i] != 0)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
