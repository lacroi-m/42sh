/*
** my_free_tab.c for all in /home/meridjm/Rendu/PSU_2015_minishell2/libmy/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Tue Mar 29 13:38:47 2016 Mehdi Meridja
** Last update Tue Mar 29 13:38:59 2016 Mehdi Meridja
*/

#include <stdlib.h>

#include "my.h"

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (i < my_strlen_tab(tab))
    free(tab[i++]);
  free(tab);
  return ;
}
