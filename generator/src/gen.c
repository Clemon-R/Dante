/*
** gen.c for generator in /home/raphael.goulmot/rendu/dante/generator
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr 29 18:02:20 2017 Raphaël Goulmot
** Last update Mon May  1 14:19:14 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "gen.h"

static char	**create_grid(const uint width, const uint height)
{
  char		**new;
  int		i;

  new = malloc(sizeof(char *) * (height + 1));
  if (!new)
    return (new);
  i = 0;
  while (i < (int)height)
    new[i++] = malloc(sizeof(char) * (width + 1));
  new[i] = 0;
  return (new);
}

static t_map	*create_map(const uint width, const uint height, const bool perfect)
{
  t_map		*map;

  map = malloc(sizeof(t_map));
  if (!map)
    return (map);
  map->map = create_grid(width, height);
  map->width = width;
  map->height = height;
  map->perfect = perfect;
  return (map);
}

static void	empty_map(t_map	*map)
{
  int		y;
  int		x;

  y = 0;
  if (!map)
    return;
  while (map->map && y < (int)map->height)
    {
      x = 0;
      while (map->map[y] && x < (int)map->width)
	map->map[y][x++] = 'X';
      map->map[y][x] = 0;
      y++;
    }
}

static void	display_map(t_map *map)
{
  int		i;
  if (!map)
    return;
  my_printf("Width : %u\nHeight: %u\n", map->width, map->height);
  i = 0;
  while (map->map && map->map[i])
    my_printf("%s\n", map->map[i++]);
}

char	gen(const uint width, const uint height, const bool perfect)
{
  t_map	*map;

  map = create_map(width, height, perfect);
  if (!map)
    {
      my_putstr_err("ERROR: Malloc t_map !\n");
      return (84);
    }
  empty_map(map);
  display_map(map);
  minecraft(map);
  display_map(map);
  return (0);
}
