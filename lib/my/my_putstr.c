/*
** my_putstr.c for putstr in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
** 
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
** 
** Started on  Mon May  2 11:26:55 2016 virgile junique
** Last update Mon May  2 11:50:03 2016 virgile junique
*/

#include "my.h"

void	my_putstr(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}
