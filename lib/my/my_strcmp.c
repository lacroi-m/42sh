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
