/*
** my_getnbr.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:38:30 2016 Mehdi Meridja
** Last update Tue Mar 29 13:38:36 2016 Mehdi Meridja
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	res;

  if (*str == '-')
    return (-my_getnbr(str + 1));
  if (*str == '+')
    return (my_getnbr(str + 1));
  res = 0;
  while (*str)
    {
      res = res * 10;
      res = res + *str - '0';
      str = str + 1;
    }
  return (res);
}
