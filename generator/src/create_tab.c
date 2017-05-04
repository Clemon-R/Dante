/*
** create_tab.c for  in /home/tdebrand/dante/generator/src
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon May  1 15:31:53 2017 Thomas DEBRAND PASSARD
** Last update Thu May  4 16:15:32 2017 Thomas DEBRAND PASSARD
*/

#include "utils.h"
#include "gen.h"
#include <stdio.h>
#include <time.h>

char	**finish_tab(char **tab, t_map *map)
{
  int	x = 0;
  int	y = 0;
  int	value_rand = 0;
  int	boucle = 0;

  map->x = 0;
  map->y = 0;
  tab[0][0] = '*';
  srand(time(NULL));
  while (1 || boucle++)
    {
      (value_rand = rand() % 4) == 1 ? tab = if_up(tab, map) :
	value_rand == 2 ? tab = if_down(tab, map) :
	value_rand == 3 ? tab = if_right(tab, map) :
	value_rand == 0 ? tab = if_left(tab, map) : 0;
      if ((map->x == map->height && map->y == map->width)
	  || (map->x == map->height && map->y + 1 == map->width)
	  || (map->x + 1 == map->height && map->y == map->width)
	  || (map->x + 1 == map->height && map->y + 1 == map->width))
	{
	  tab[map->height][map->width - 1] = ((map->height % 2 == 1) && (map->width % 2 == 1)) ? '*' : 'X';
	  tab[map->height][map->width] = '*';
	  break;
	}
    }
  return (tab);
}

char	**create_tab(char **av)
{
  int	x;
  int	y;
  int	i1 = 0;
  int	i2 = 0;
  char	**tab;

  x = my_getnbr(av[1]);
  y = my_getnbr(av[2]);
  if (!(tab = malloc(sizeof(char *) * (x + 1))))
    return (NULL);
  while (i1 != x)
    {
      if (!(tab[i1] = malloc(sizeof(char) * (y + 1))))
	return (NULL);
      while (i2 != y)
	tab[i1][i2++] = 'X';
      tab[i1][i2 + 1] == '\0';
      i2 = 0;
      i1++;
    }
  return (tab);
}
