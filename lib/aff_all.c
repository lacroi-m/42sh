/*
** aff_all.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:40:08 2016 Mehdi Meridja
** Last update Tue Mar 29 13:40:23 2016 Mehdi Meridja
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_put_error(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar ('-');
      nb = nb * -1;
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + 48);
}
