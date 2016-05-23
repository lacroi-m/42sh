/*
** my_strcmp.c for my_strcmp in /home/da-sil_t/rendu/Systeme_Unix/42sh/PSU_2015_42sh
** 
** Made by theo da-silva
** Login   <da-sil_t@epitech.net>
** 
** Started on  Mon May 23 15:22:26 2016 theo da-silva
** Last update Mon May 23 15:22:27 2016 theo da-silva
*/

int	my_strncmp(char *s1, char *s2)
{
  int   i;
  int	j;
  
  i = 0;
  j = my_strlen(s1);
  while (s1[i] == s2[i])
    i++;
  if (j = i)
    return (0);
  else
    return (-1);
}
