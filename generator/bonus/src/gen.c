/*
** create_tab.c for  in /home/tdebrand/dante/generator/src
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon May  1 15:31:53 2017 Thomas DEBRAND PASSARD
** Last update Fri May  5 21:54:24 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "gen.h"
#include <stdio.h>
#include <time.h>
#include <unistd.h>

t_room	*create_empty_room(int y, int x)
{
  t_room	*new;

  new = malloc(sizeof(t_room));
  new->y = y;
  new->x = x;
  new->parent = 0;
  new->blocked = true;
  new->o = false;
  return (new);
}

void	create_empty_grid(t_map *map)
{
  int	y;
  int	x;

  y = 0;
  map->grid = malloc(sizeof(t_room **) * (map->height + 1));
  while (y < map->height)
    {
      x = 0;
      map->grid[y] = malloc(sizeof(t_room *) * (map->width + 1));
      while (x < map->width)
	map->grid[y][x] = create_empty_room(y, x++);
      map->grid[y][x] = 0;
      y++;
    }
  map->grid[y] = 0;
}

t_room	*next_room(t_map *map, t_room *current)
{
  char	dir;
  t_room	*new;

  current->o = true;
  dir = get_random(0, 1) ? 1 : -1;
  if (get_random(0, 1))
    new = move_h(map, current, dir);
  else
    new = move_v(map, current, dir);
  display_map(map);
  my_putchar('\n');
  usleep(100000);
  current->o = false;
  if (new && new != current->parent)
    current = new;
  else if (current->parent && !check_move(map, current))
    if (current->parent != current)
      current = current->parent;
    else
      current = map->end;
  if (current)
    current->blocked = false;
  return (current);
}

void	gen(t_map *map)
{
  t_room	*current;
  char		dir;

  create_empty_grid(map);
  srand(time(0));
  map->start = map->grid[0][0];
  map->end = map->grid[map->height - 1][map->width - 1];
  current = map->start;
  current->blocked = false;
  while (current && current != map->end)
      current = next_room(map, current);
  current = map->end;
  while (current && current != map->start)
    {
      current = current->parent;
      if (current && !check_move(map, current))
	continue;
      while (current && check_move(map, current))
	current = next_room(map, current);
    }
  map->end = map->start;
  display_map(map);
}
