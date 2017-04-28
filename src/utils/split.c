/*
** split.c for corewar in /home/raphael.goulmot/corewar
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Mar 31 19:30:14 2017 Raphaël Goulmot
** Last update Sat Apr  1 01:48:49 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdlib.h>

int     length_word(char *str, int start, char c)
{
  int   i;

  i = start;
  while (str && str[i] && str[i] != c && ++i);
  return (i - start);
}

int     count_words(char *str, char c)
{
  int   i;
  int   size;

  i = 0;
  size = str && str[0] ? 1 : 0;
  while (str && str[i])
    if (i++ > 0 && str[i - 1] == c && str[i - 2] != c)
      size++;
  return (size);
}

char    **split(char *str, char c)
{
  int   i;
  char  **new;
  int   l;
  int   tmp;

  i = tmp = 0;
  l = -1;
  new = malloc(sizeof(char *) * (count_words(str, c) + 1));
  while (str && str[i++])
    {
      if (l >= 0 && str[i - 1] == c)
	{
	  new[l][tmp] = 0;
	  tmp = 0;
	}
      if (!tmp && str[i - 1] != c)
	new[++l] = malloc(sizeof(char) * (length_word(str, i - 1, c) + 1));
      if (str[i - 1] != c)
	new[l][tmp++] = str[i - 1];
    }
  if (tmp)
    new[l][tmp] = 0;
  new[tmp ? l + 1 : l] = 0;
  return (new);
}
