/*
** my_getnbr.c for my_getnbr in /home/juniqu_v/rendu/PSU_2015_42sh/lib/my
**
** Made by virgile junique
** Login   <juniqu_v@epitech.net>
**
** Started on  Sun Jun  5 11:46:23 2016 virgile junique
** Last update Sun Jun  5 11:47:30 2016 virgile junique
*/

#include "my.h"

int             my_getnbr(char *s)
{
  int           nb;

  nb = 0;
  while (*s == ' ' || *s == '\t')
    s++;
  if (*s == '-')
    return (-1);
  while (*s)
    {
      if (*s > '9' || *s < '0')
        return (-1);
      nb = nb * 10 + *s - '0';
      s++;
    }
  return (nb);
}
