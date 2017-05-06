/*
** get_room.c for breadth in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat May  6 18:24:22 2017 Raphaël Goulmot
** Last update Sat May  6 18:24:38 2017 Raphaël Goulmot
*/

#include "breadth.h"

t_room  *get_room(t_map *map, int y, int x)
{
  if (y >= 0 && y < map->height && x >= 0 && x < map->width)
    return (map->grid[y][x]);
  return (0);
}
