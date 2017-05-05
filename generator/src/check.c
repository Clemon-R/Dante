/*
** check.c for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri May  5 21:03:26 2017 Raphaël Goulmot
** Last update Fri May  5 21:53:19 2017 Raphaël Goulmot
*/

#include "gen.h"

char    check_arround(t_map *map, t_room *current, char axe)
{
  int   y;
  int   x;
  int   *tmp;
  int   max;
  char  check;

  check = 1;
  y = current->y;
  x = current->x;
  tmp = axe ? &x : &y;
  max = axe ? map->width : map->height;
  *tmp += 1;
  if (*tmp < max && !map->grid[y][x]->blocked)
    check = 0;
  *tmp -= 2;
  if (*tmp >= 0 && !map->grid[y][x]->blocked)
    check = 0;
  return (check);
}

char    check_h(t_map *map, t_room *current, char dir)
{
  t_room        *first;
  t_room        *second;
  char          check;

  check = 1;
  first = current->x + dir >= 0 && current->x + dir < map->width
    ? map->grid[current->y][current->x + dir] : 0;
  second = current->x + dir * 2 >= 0 && current->x + dir * 2 < map->width
    ? map->grid[current->y][current->x + dir * 2] : 0;
  if ((!first || !first->blocked || !check_arround(map, first, 0))
	  || (map->perfect && second && !second->blocked ))
    check = 0;
  return (check);
}

char    check_v(t_map *map, t_room *current, char dir)
{
  t_room        *first;
  t_room        *second;
  char          check;

  check = 1;
    first = current->y + dir >= 0 && current->y + dir < map->height
      ? map->grid[current->y + dir][current->x] : 0;
      second = current->y + dir * 2 >= 0 && current->y + dir * 2 < map->height
	? map->grid[current->y + dir * 2][current->x] : 0;
      if ((!first || !first->blocked || !check_arround(map, first, 1))
	  || (map->perfect && second && !second->blocked))
	check = 0;
      return (check);
}

char    check_move(t_map *map, t_room *current)
{
  if (check_h(map, current, 1) || check_v(map, current, 1)
      || check_h(map, current, -1) || check_v(map, current, -1))
    return (1);
  return (0);
}
