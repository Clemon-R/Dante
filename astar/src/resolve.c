/*
** resolve.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 16:36:39 2017 Raphaël Goulmot
** Last update Sat May 13 14:18:39 2017 Raphaël Goulmot
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
    size1 = (map->height - (first->y + 1)) + (map->width - (first->x + 1));
  size2 = (map->height - (second->y + 1)) + (map->width - (second->x + 1));
  if (!first || size1 > size2)
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

t_room	*resolve_pos(t_map *map, t_room *old)
{
  int	i;
  char	offset[] = {1, 0, 0, 1, -1, 0, 0, -1};
  int	tmp_x;
  int	tmp_y;
  t_room	*current;

  i = 0;
  current = 0;
  while (i < 8)
    {
      tmp_y = old->y + offset[i + 1];
      tmp_x = old->x + offset[i];
      if (check_room(map, tmp_y, tmp_x)
	  && more_short(map, current, map->grid[tmp_y][tmp_x]))
	current = map->grid[tmp_y][tmp_x];
      i += 2;
    }
  return (current);
}

static t_room	*change_path(t_room **current, t_room *new)
{
  t_room	*tmp;

  tmp = *current;
  (*current)->visited = false;
  new->parent = (*current)->parent;
  *current = (*current)->parent;
  tmp->parent = 0;
  return (new);
}

void	resolve(t_map *map)
{
  t_room	*current;
  t_room	*new;
  t_room	*tmp;

  new = map->start;
  while ((current = new) && map->end != new)
    {
      if (!(new = resolve_pos(map, current)))
	new = current->parent;
      if (current->parent && current->parent != new
	  && (tmp = resolve_pos(map, current->parent))
	  && more_short(map, new, tmp))
	new = change_path(&current, tmp);
      if (new && current->parent != new)
	{
	  new->visited = true;
	  new->parent = current;
	}
      if (current->parent == new)
	current->parent = 0;
    }
}
