/*
** my_putchar.c for putchar in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Mon May  2 11:26:25 2016 virgile junique
** Last update Mon May 23 21:01:35 2016 virgile junique
*/

#include "my.h"

void	my_putchar(char c, int fd)
{
  if (write (fd, &c, 1) < 0)
    exit(-1);
}
