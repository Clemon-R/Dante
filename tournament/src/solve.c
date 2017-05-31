/*
** solve.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 15:46:24 2017 Raphaël Goulmot
** Last update Wed May 31 05:48:53 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "line.h"
#include "depth.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void    load_line(char *line, t_room **grid_line, int y)
{
  t_room        *room;
  int           x;

  x = 0;
  while (line && *line && *line != '\n' && grid_line)
    {
      if (!(room = malloc(sizeof(t_room))))
	  return;
      room->y = y;
      room->x = x;
      room->visited = false;
      room->parent = 0;
      room->blocked = *line != '*';
      grid_line[x++] = room;
      line++;
    }
}

void	load_map(t_map *map, int fid)
{
  int	tmp;
  char	*line;
  t_room	***new;

  while ((line = get_next_line(fid)))
    {
      tmp = 0;
      map->height++;
      if (!map->width)
	map->width = my_strlen(line);
      new = malloc(sizeof(t_room **) * (map->height + 1));
      new[map->height] = 0;
      while (map->grid && map->grid[tmp])
	new[tmp] = map->grid[tmp++];
      if (map->grid)
	free(map->grid);
      map->grid = new;
      map->grid[tmp] = malloc(sizeof(t_room *) * (map->width + 1));
      map->grid[tmp][map->width] = 0;
      load_line(line, map->grid[tmp], tmp);
      free_safe((void *)line);
    }
}

t_map	*load_file(char *file_name)
{
  t_map	*map;
  int	fid;

  if (!(map = malloc(sizeof(t_map))))
    return (0);
  if ((fid = open(file_name, O_RDONLY)) < 0)
    return (map);
  map->width = 0;
  map->height = 0;
  map->grid = 0;
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
		     : map->grid[y][x]->parent ? 'o' : '*');
	  x++;
	}
      my_putchar('\n');
      y++;
    }
}

void	depth(char *file_name)
{
  t_map	*map;
  int	y;
  int	x;

  map = load_file(file_name);
  resolve(map);
  y = 0;
  while (map->grid && map->grid[y] && !(x = 0))
    {
      while (map->grid[y][x])
	free(map->grid[y][x++]);
      free(map->grid[y]);
      y++;
    }
  free(map->grid);
  free(map);
}
