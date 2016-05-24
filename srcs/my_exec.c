/*
** my_exec.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs
**
** Made by Mehdi Meridja
** Login   <meridj_m@epitech.net>
**
** Started on  Mon May 23 09:12:46 2016 Lemeh
** Last update Tue May 24 14:43:57 2016 Lemeh
*/

#include "42sh.h"
#include "builtins.h"

static int     my_fork_local(char **envp, char **command_tab)
{
  pid_t		pid;

  if ((access(command_tab[0], F_OK) == -1)
      || (access(command_tab[0], X_OK) == -1)
      || (opendir(command_tab[0])) != NULL)
    {
      fprintf(stderr, "%s: Command not found.\n", command_tab[0]);
      fflush(stdout);
      return (-1);
    }
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    execve(command_tab[0], command_tab, envp);
  else
    wait(NULL);
  return (0);
}

static int     my_fork(char *command, char **command_tab, char **envp)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    execve(command, command_tab, envp);
  else
    wait(NULL);
  return (0);
}

static char	*my_access(char **command_tab, t_params *p)
{
  int		i;
  char		*command;

  i = -1;
  if (p->path_tab != NULL)
    my_free_ctab(p->path_tab);
  p->path_tab = my_pathway(p->env);
  while (p->path_tab[++i] != NULL)
    {
      command = my_strcat(p->path_tab[i], command_tab[0]);
      if ((access(command, X_OK)) == 0)
	return (command);
      free(command);
    }
  return (NULL);
}

void	my_exec(t_params *p)
{
  char	**command_tab;
  char	*command;

  command_tab = my_str_to_wordtab(p->prompt);
  if ((strncmp(command_tab[0], "./", 2)) == 0)
    my_fork_local(p->env_tab, command_tab);
  else
    {
      if ((command = my_access(command_tab, p)) == NULL)
	fprintf(stderr, "%s: Command not found.\n", command_tab[0]);
      else
	my_fork(command, command_tab, p->env_tab);
    }
  free(command);
  my_free_ctab(command_tab);
  return ;
}
