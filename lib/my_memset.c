/*
** my_memset.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:37:53 2016 Mehdi Meridja
** Last update Tue Mar 29 13:37:56 2016 Mehdi Meridja
*/

#include "my.h"
#include <stdlib.h>

char    *my_memset(char *str, int c, int n)
{
  int   i;

  if ((str = malloc(sizeof(char) * (4 + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i < n)
    str[i++] = c;
  str[i] = '\0';
  return (str);
}
