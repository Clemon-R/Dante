/*
** resolve.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 16:36:39 2017 Raphaël Goulmot
** Last update Wed May 31 05:55:52 2017 Raphaël Goulmot
*/

#include "depth.h"
#include "utils.h"

t_room	*move_h(t_map *map, t_room *old, int dir)
{
  int	x;
  t_room	*tmp;

  if ((x = old->y + -1 * dir) >= 0 && x < map->height
      && (tmp = map->grid[x][old->x]) && !tmp->blocked && !tmp->visited)
    return (tmp);
  else if ((x = old->x + dir) >= 0 && x < map->width
      && (tmp = map->grid[old->y][x]) && !tmp->blocked && !tmp->visited)
    return (tmp);
  else if ((x = old->y + dir) >= 0 && x < map->height
	   && (tmp = map->grid[x][old->x]) && !tmp->blocked && !tmp->visited)
    return (tmp);
  return (0);
}

t_room	*move_v(t_map *map, t_room *old, int dir)
{
  int   y;
  t_room        *tmp;

  if ((y = old->x + -1 * dir) >= 0 && y < map->width
      && (tmp = map->grid[old->y][y]) && !tmp->blocked && !tmp->visited)
    return (tmp);
  else if ((y = old->y + dir) >= 0 && y < map->height
      && (tmp = map->grid[y][old->x]) && !tmp->blocked && !tmp->visited)
    return (tmp);
  else if ((y = old->x + dir) >= 0 && y < map->width
	   && (tmp = map->grid[old->y][y]) && !tmp->blocked && !tmp->visited)
    return (tmp);
  return (0);
}

t_room	*resolve_pos(t_map *map, t_room *old)
{
  t_room	*current;
  int		dir_y;
  int		dir_x;

  current = 0;
  dir_x = old->parent ? old->x - ((t_room *)old->parent)->x : 1;
  if (dir_x != 0)
    current = move_h(map, old, dir_x);
  else
    {
      dir_y = old->parent ? old->y - ((t_room *)old->parent)->y : 0;
      if (dir_y != 0)
	current =  move_h(map, old, dir_y);
    }
  return (current);
}

void	resolve(t_map *map)
{
  t_room	*current;
  t_room	*new;

  current = map->start;
  while (map->end != current)
    {
      if (!(new = resolve_pos(map, current)))
	new = current->parent;
      new->visited = true;
      if (new != current->parent)
	new->parent = current;
      else
	current->parent = 0;
      current = new;
    }
  map->start->parent = map->start;
  display_map(map);
}
