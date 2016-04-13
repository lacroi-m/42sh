/*
** malloc.c for all in /home/meridj/Rendu/minishell1/lib/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Mon Apr 11 15:43:28 2016 Mehdi Meridja
** Last update Mon Apr 11 15:46:52 2016 Mehdi Meridja
*/

#include <stdlib.h>

char	*malloc_x(int size)
{
  char	*str;

  if ((str = malloc(sizeof(char) * size)) == NULL)
    return (NULL);
  return (str);
}
