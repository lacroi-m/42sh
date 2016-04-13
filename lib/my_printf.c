/*
** my_printf.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:36:40 2016 Mehdi Meridja
** Last update Wed Apr 13 10:01:42 2016 Mehdi
*/

#include <stdlib.h>

#include "my.h"

ptr_func	*tab_func()
{
  ptr_func	*tab;

  if ((tab = malloc(sizeof(char) * 5)) == NULL)
    return (NULL);
  tab[0] = &flag_c;
  tab[1] = &flag_d_i;
  tab[2] = &flag_s;
  tab[3] = &flag_modulo;
  return (tab);
}

int		check_flag(char c, va_list ap)
{
  int		j;
  char		*str2;
  ptr_func	*tab;

  j = 0;
  tab = tab_func();
  str2 = "cds%";
  while (str2[j] != c && j < 6)
    j++;
  if (str2[j] != c)
    return (-1);
  else
    tab[j](ap);
  return (0);
}

int		my_printf(char *format, ...)
{
  int		i;
  va_list	ap;

  i = 0;
  va_start(ap, format);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  i++;
	  check_flag(format[i++], ap);
	}
      else
	my_putchar(format[i++]);
    }
  va_end(ap);
  return (0);
}
