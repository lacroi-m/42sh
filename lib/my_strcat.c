/*
** my_strcat.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:26:17 2016 Mehdi Meridja
** Last update Tue Mar 29 13:34:09 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  int	k;
  char	*dest_final;
  int	size;

  size = (my_strlen(dest)) + (my_strlen(src)) + 2;
  k = 0;
  i = 0;
  j = 0;
  if ((dest_final = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (dest[i] != 0)
    {
      dest_final[i] = dest[i];
      i++;
    }
  j = my_strlen(dest);
  while (src[k] != '\0')
    dest_final[j++] = src[k++];
  dest_final[j] = '\0';
  return (dest_final);
}
