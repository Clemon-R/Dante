/*
** my_put_tab.c for  in /home/tdebrand/dante/generator/src
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon May  1 15:45:16 2017 Thomas DEBRAND PASSARD
** Last update Mon May  1 16:37:35 2017 Thomas DEBRAND PASSARD
*/

#include "utils.h"

void	my_put_tab(char **tab)
{
  int	i = 0;

  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}
