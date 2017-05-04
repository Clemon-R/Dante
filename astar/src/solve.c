/*
** solve.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 15:46:24 2017 Raphaël Goulmot
** Last update Thu May  4 16:17:09 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "line.h"
#include "astar.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void	load_line(char *line, t_room **grid_line, int y)
{
  t_room	*room;
  int		x;

  x = 0;
  while (line && *line && *line != '\n' && grid_line)
    {
      room = malloc(sizeof(t_room));
      room->y = y;
      room->x = x;
      room->visited = false;
      room->parent = 0;
      room->blocked = false;
      if (*line != '*')
	room->blocked = true;
      *grid_line = room;
      line++;
      grid_line++;
      x++;
    }
}

void	load_map(t_map *map, int fid)
{
  int	y;
  char	*line;

  y = 0;
  map->grid = malloc(sizeof(t_room **) * (map->height + 1));
  while (y < map->height)
    {
      map->grid[y] = malloc(sizeof(t_room *) * (map->width + 1));
      map->grid[y][map->width] = 0;
      line = get_next_line(fid);
      if (line)
	{
	  load_line(line, map->grid[y], y);
	  free_safe((void *)line);
	}
      y++;
    }
  map->grid[map->height] = 0;
}

t_map	*load_file(char *file_name)
{
  t_map	*map;
  int	fid;
  char	*line;
  char	**args;

  map = malloc(sizeof(t_map));
  if (!map)
    return (0);
  fid = open(file_name, O_RDONLY);
  if (fid < 0)
    return (map);
  line = get_next_line(fid);
  if (line)
    args = split(line, ',');
  free_safe((void *)line);
  if (!args)
    return (map);
  map->width = my_getnbr(args[0]);
  map->height = my_getnbr(args[1]);
  free_wordtab((void **)args);
  load_map(map, fid);
  close(fid);
  map->start = map->grid[0][0];
  map->end = map->grid[map->height - 1][map->width - 1];
  return (map);
}

void	display_map(t_map *map)
{
  int	y;
  int	x;

  y = 0;
  while (map->grid && map->grid[y])
    {
      x = 0;
      while (map->grid[y][x])
	{
	  my_putchar(map->grid[y][x]->blocked  == true ? 'X'
		     : map->grid[y][x]->parent ? 'O' : '*');
	  x++;
	}
      my_putchar('\n');
      y++;
    }
}

void	astar(char *file_name)
{
  t_map	*map;

  map = load_file(file_name);
  resolve(map);
}
