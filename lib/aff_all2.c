/*
** aff_all2.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:39:55 2016 Mehdi Meridja
** Last update Tue Mar 29 13:39:59 2016 Mehdi Meridja
*/

#include "my.h"

void	my_put_nbr_base(long nb, char *base)
{
  int	j;
  long	div;
  long	size;

  size = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  div = 1;
  while ((nb / div) >= size)
    div = div * size;
  while (div > 0)
    {
      j = (nb / div) % size;
      my_putchar(base[j]);
      div = div / size;
    }
}
