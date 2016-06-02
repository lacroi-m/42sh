/*
** test_system2.c for all in /home/meridj/Rendu/PSU_2015_42sh/lib/my/
**
** Made by Mehdi Meridja
** Login   <meridj_m@meridj_m@epitech.eu>
**
** Started on  Thu Jun  2 11:00:42 2016 Mehdi Meridja
** Last update Thu Jun  2 11:11:59 2016 Mehdi Meridja
*/

#include "my.h"

char	**xmalloc_tab(int size)
{
  char	**tab;

  if ((tab = malloc(size)) == NULL)
    return (NULL);
  return (tab);
}
