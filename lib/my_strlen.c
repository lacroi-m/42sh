/*
** my_strlen.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:25:03 2016 Mehdi Meridja
** Last update Tue Apr 12 11:10:30 2016 Mehdi Meridja
*/

#include <my.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strlen_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
