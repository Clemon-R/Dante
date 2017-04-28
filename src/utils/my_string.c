/*
** my_string.c for default in /home/raphael.goulmot/default_struct
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Wed Mar  1 22:16:49 2017 Raphaël Goulmot
** Last update Fri Apr 28 17:57:41 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdlib.h>

void	free_wordtab(void **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i++])
    free(tab[i-1]);
  if (tab)
    free(tab);
}

void	free_safe(void *str)
{
  if (str)
    free(str);
  str = 0;
}

char	my_strstr(char *str, char *arg)
{
  char	*clone;
  int	i;
  char	check;

  clone = str;
  while (*clone && !(i = 0))
    {
      check = 0;
      while (*(clone + i) && arg[i] && !check)
	{
	  if (*(clone + i) != arg[i])
	    check = 1;
	  i++;
	}
      if (!check && my_strlen(arg) == i)
	return (1);
      clone++;
    }
  return (0);
}

char    *my_strcpy(char *str1, char *str2)
{
  char  *new;
  int   i;
  int   n;

  n = 0;
  new = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
  i = 0;
  while (str1[i++])
    new[n++] = str1[i - 1];
  i = 0;
  while (str2[i++])
    new[n++] = str2[i - 1];
  new[n] = '\0';
  return (new);
}

char    my_strcmp(char *str1, char *str2)
{
  int   i;

  i = 0;
  while ((str1[i] || str2[i]) && ++i)
    if (str1[i - 1] != str2[i - 1])
      return (0);
  return (1);
}
