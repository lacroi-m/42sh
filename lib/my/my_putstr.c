/*
** my_putstr.c for putstr in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 11:26:55 2016 virgile junique
** Last update Mon May 23 15:51:05 2016 virgile junique
*/

#include "my.h"

int	my_putstr(char *str, int fd, int value)
{
  if (write(fd, str, my_strlen(str)) <= 0)
    my_exit(-1);
  return (value);
}
