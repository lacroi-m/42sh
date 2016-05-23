/*
** my_exec.c for 42sh in /home/meridj/Rendu/PSU_2015_42sh/srcs
**
** Made by Mehdi Meridja
** Login   <meridj_m@epitech.net>
**
** Started on  Mon May 23 09:12:46 2016 Lemeh
** Last update Mon May 23 11:47:09 2016 Lemeh
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

#include "42sh.h"

static int     my_fork_local(char **envp, char **command_tab)
{
  pid_t		pid;

  if ((access(command_tab[0], F_OK) == -1)
      || (access(command_tab[0], X_OK) == -1)
      || (opendir(command_tab[0])) != NULL)
    {
      fprintf(stderr, "error: no such file or directory\n");
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
  free(command);
  return (0);
}

static int	my_access(char **command_tab, t_params *p)
{
  int		i;
  char		*command;

  i = -1;
  while (p->path_tab[++i] != NULL)
    {
      command = my_strcat(p->path_tab[i], command_tab[0]);
      if ((access(command, X_OK)) == 0)
	{
	  my_fork(command, command_tab, p->env_tab);
	  return (1);
	}
      free(command);
    }
  return (0);
}

void	my_exec(t_params *p)
{
  char	**command_tab;
  int	ret;

  ret = -1;
  command_tab = my_str_to_wordtab(p->prompt);
  if ((strncmp(command_tab[0], "./", 2)) == 0)
    my_fork_local(p->env_tab, command_tab);
  else
    ret = my_access(command_tab, p);
  if (ret == 0)
    fprintf(stderr, "%s: Command not found\n", command_tab[0]);
  my_free_tab(command_tab);
  return ;
}
