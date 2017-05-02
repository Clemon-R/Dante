/*
** resolve.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 16:36:39 2017 Raphaël Goulmot
** Last update Tue May  2 18:31:50 2017 Raphaël Goulmot
*/

#include "astar.h"
#include "utils.h"

char	more_short(t_map *map, t_room *first, t_room *second)
{
  int	defaul;
  int	size1;
  int	size2;

  defaul = map->end->y + map->end->x;
  if (first)
    size1 = first->y * first->x;
  size2 = second->y * second->x;
  if (!first || size1 < size2)
    return (1);
  return (0);
}

t_room	*resolve_pos(t_map *map, int y, int x, t_room *old)
{
  int	i;
  char	offset[] = {1, 0, 0, -1, -1, 0, 0, 1};
  int	tmp_x;
  int	tmp_y;
  t_room	*current;

  i = 0;
  current = 0;
  while (i < 8)
    {
      tmp_y = y + offset[i + 1];
      tmp_x = x + offset[i];
      if (tmp_y >= 0 && tmp_x >= 0 && tmp_y < map->height && tmp_x < map->width
	  && !map->grid[tmp_y][tmp_x]->blocked && !map->grid[tmp_y][tmp_x]->visited
	  && more_short(map, current, map->grid[tmp_y][tmp_x]))
	current = map->grid[tmp_y][tmp_x];
      i += 2;
    }
  if (current)
    current->parent = old;
  return (current);
}

void	display_path(t_map *map, t_room *start)
{
  t_room	*current;

  current = start;
  current->display = true;
  while ((current = current->parent))
    current->display = true;
}

void	resolve(t_map *map)
{
  t_room	*current;
  t_room	*new;

  current = map->start;
  while (map->end != current)
    {
      if (!(new = resolve_pos(map, current->y, current->x, current)))
	new = current->parent;
      new->visited = true;
      current = new;
    }
  display_path(map, current);
  display_map(map);
}
