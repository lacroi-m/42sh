/*
** my_strncpy.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:24:48 2016 Mehdi Meridja
** Last update Tue Mar 29 13:25:13 2016 Mehdi Meridja
*/

#include "my.h"
#include <stdlib.h>

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  while (src[i] != 0 && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
