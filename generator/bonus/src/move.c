/*
** move.c for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri May  5 21:07:27 2017 Raphaël Goulmot
** Last update Fri May  5 21:10:47 2017 Raphaël Goulmot
*/

#include "gen.h"
#include "utils.h"

void    display_map(t_map *map)
{
  int   x;
  int   y;

  y = 0;
  while (map->grid && map->grid[y])
    {
      x = 0;
      while (map->grid[y][x++])
	my_putchar(map->grid[y][x - 1]->o ? 'O'
		   : map->grid[y][x - 1]->blocked ? 'X' : '*');
      my_putchar('\n');
      y++;
    }
}

int      get_random(int a, int b)
{
  return (rand()%(b - a + 1) + a);
}

t_room  *move_h(t_map *map, t_room *current, char dir)
{
  t_room        *new;

  new = 0;
  if (current->x + dir >= 0 && current->x + dir < map->width)
    {
      new = map->grid[current->y][current->x + dir];
      if (new == current || !check_h(map, current, dir))
	return (0);
      new->parent = current;
      new->blocked = false;
    }
  return (new);
}

t_room  *move_v(t_map *map, t_room *current, char dir)
{
  t_room        *new;

  new = 0;
  if (current->y + dir >= 0 && current->y + dir < map->height)
    {
      new = map->grid[current->y + dir][current->x];
      if (new == current || !check_v(map, current, dir))
	return (0);
      new->parent = current;
      new->blocked = false;
    }
  return (new);
}
