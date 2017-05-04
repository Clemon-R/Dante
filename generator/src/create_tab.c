/*
** create_tab.c for  in /home/tdebrand/dante/generator/src
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon May  1 15:31:53 2017 Thomas DEBRAND PASSARD
** Last update Thu May  4 15:10:00 2017 Thomas DEBRAND PASSARD
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
  while (map->x + 1 != map->height || map->y + 1 != map->width)
    {
      value_rand = rand() % 4;
      /* my_put_nbr(value_rand);			// */
      /* my_putstr(" - boucle numéro : ");		// */
      /* my_put_nbr(boucle);			// */
      /* my_putchar('\n');				// */
      /* my_putstr("x = ");			// */
      /* my_put_nbr(map->x);			// */
      /* my_putstr(" / y = ");			// */
      /* my_put_nbr(map->y);			// */
      /* my_putchar('\n');				// */
      if (value_rand == 1)
	tab = if_up(tab, map);
      else if (value_rand == 2)
	tab = if_down(tab, map);
      else if (value_rand == 3)
	tab = if_right(tab, map);
      else if (value_rand == 0)
	tab = if_left(tab, map);
      if ((map->x == map->height && map->y == map->width)
	  || (map->x == map->height && map->y + 1 == map->width)
	  || (map->x + 1 == map->height && map->y == map->width)
	  || (map->x + 1 == map->height && map->y + 1 == map->width ))
	{
	  tab[map->height][map->width] = '*';
	  break;
	}
      //my_put_tab(tab);
      boucle++;
    }
  my_put_tab(tab);
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
