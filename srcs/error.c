/*
** error.c for error in /home/juniqu_v/rendu/PSU_2015_42sh/srcs
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sun Jun  5 16:21:44 2016 virgile junique
** Last update Sun Jun  5 16:27:07 2016 virgile junique
*/

#include "42sh.h"

int	my_error(char *str, int value)
{
  if (value == 1)
  {
    my_putstr(str, 2, 0);
    return (my_putstr(": Command not found.\n", 2, 1));
  }
  else if (value == 2)
    {
      my_putstr(str, 2, 0);
      return (my_putstr(": Wrong arguments.\n", 2, 2));
    }
  return (0);
}
