/*
** resolve.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 16:36:39 2017 Raphaël Goulmot
** Last update Sun May  7 16:07:15 2017 Raphaël Goulmot
*/

#include "astar.h"
#include "utils.h"
#include <unistd.h>

char	more_short(t_map *map, t_room *first, t_room *second)
{
  int	size1;
  int	size2;

  size1 = 0;
  if (first)
    size1 = (map->height - first->y) * (map->width - first->x);
  size2 = (map->height - second->y) * (map->width - second->x);
  if (!first || size1 < size2)
    return (1);
  return (0);
}

char	check_room(t_map *map, int y, int x)
{
  if (y >= 0 && y < map->height && x >= 0 && x < map->width
      && !map->grid[y][x]->blocked && !map->grid[y][x]->visited)
    return (1);
  return (0);
}

t_room	*resolve_pos(t_map *map, int y, int x, t_room *old)
{
  int	i;
  char	offset[] = {0, 1, 1, 0};
  int	tmp_x;
  int	tmp_y;
  t_room	*current;

  i = 0;
  current = 0;
  while (i < 4)
    {
      tmp_y = y + offset[i + 1];
      tmp_x = x + offset[i];
      if (check_room(map, tmp_y, tmp_x)
	  && more_short(map, current, map->grid[tmp_y][tmp_x]))
	current = map->grid[tmp_y][tmp_x];
      i += 2;
    }
  if (current)
    current->parent = old;
  return (current);
}

void	resolve(t_map *map)
{
  t_room	*current;
  t_room	*new;

  new = 0;
  current = map->start;
  while (current && map->end != current)
    {
      if (!(new = resolve_pos(map, current->y
		      , current->x, current)))
	new = current->parent;
      if (new)
	new->visited = true;
      if (current->parent == new)
	current->parent = 0;
      current = new;
    }
  if (current == map->end)
    map->start->parent = map->start;
  display_map(map);
}
