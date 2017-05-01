/*
** mincraft.c for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 14:12:16 2017 Raphaël Goulmot
** Last update Mon May  1 15:27:21 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "gen.h"
#include <time.h>

static int	get_random(int a, int b)
{
  return (rand()%(b - a + 1) + a);
}

static char	check_around(const t_map *map, int y, int x)
{
  int		count;

  count = 0;
  if (x > 0 && map->map[y][x - 1] == '*')
    count++;
  if (x < (int)map->width - 1 && map->map[y][x + 1] == '*')
    count++;
  if (count > 1)
    return (count);
  if (y > 0 && map->map[y - 1][x] == '*')
    count++;
  if (y < (int)map->height - 1 && map->map[y + 1][x] == '*')
    count++;
  return (count);
}

void	minecraft(t_map *map)
{
  int	y;
  int	x;
  int	*axe;
  char	dir;
  int	old_x[2];
  int	old_y[2];
  char	try;

  srand(time(0));
  my_printf("Debut du minage...\n");
  y = 0;
  x = 0;
  try = 0;
  old_x[0] = x;
  old_y[0] = y;
  map->map[y][x] = '*';
  while (try != 3)
    {
      old_x[1] = old_x[0];
      old_y[1] = old_y[0];
      old_y[0] = y;
      old_x[0] = x;
      axe = get_random(0, 1) ? &y : &x;
      if (axe == &y)
	dir = y > 0 && y != (int)map->height - 1 ? get_random(0, 1) : y > 0 ? 0 : 1;
      else
	dir = x > 0 && x != (int)map->width - 1 ? get_random(0, 1) : x > 0 ? 0 : 1;
      *axe += dir ? dir : -1;
      if ((y == old_y[1] && x == old_x[1]) || ((try = check_around(map, y, x)) != 1)) 
	*axe -= dir ? dir : -1;
      my_printf("Pos Y: %d Pos X: %d\n", y, x);
      map->map[y][x] = '*';
    }
}
