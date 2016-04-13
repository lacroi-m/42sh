/*
** flag_printf.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:39:36 2016 Mehdi Meridja
** Last update Tue Mar 29 13:39:40 2016 Mehdi Meridja
*/

#include <stdarg.h>

#include "my.h"

void    flag_d_i(va_list ap)
{
  my_putnbr(va_arg(ap, int));
}

void    flag_c(va_list ap)
{
  my_putchar((char) va_arg(ap, int));
}

void    flag_s(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void    flag_modulo(va_list ap)
{
  (void)ap;
  my_putchar('%');
}
