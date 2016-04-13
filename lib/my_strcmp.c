/*
** my_strcmp.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:25:46 2016 Mehdi Meridja
** Last update Tue Mar 29 13:25:55 2016 Mehdi Meridja
*/

#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (-2);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] > s2[i])
        return (1);
      else if (s1[i] < s2[i])
        return (-1);
      i = i + 1;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
      if (s1[i] > s2[i])
        return (1);
      else if (s1[i] < s2[i])
        return (-1);
      i = i + 1;
    }
  if (s2[i] != '\0')
    return (-1);
  return (0);
}
