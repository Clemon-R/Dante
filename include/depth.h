/*
** astar.h for asatr in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 15:54:44 2017 Raphaël Goulmot
** Last update Thu May  4 12:07:47 2017 Raphaël Goulmot
*/

#ifndef ASTAR_H_
# define ASTAR_H_

# include <stdbool.h>

typedef struct	s_room
{
  int		x;
  int		y;
  bool		visited;
  bool		blocked;
  void		*parent;
  bool		display;
}		t_room;

typedef struct	s_map
{
  t_room	***grid;
  t_room	*start;
  t_room	*end;
  int		width;
  int		height;
}		t_map;

//Fichier solve.c
void	display_map(t_map *map);
void	load_line(char *line, t_room **grid_line, int y);
void	load_map(t_map *amp, int fid);
t_map	*load_file(char *file_name);
void	depth(char *file_name);

//Fichier resolve.c
void	resolve(t_map *map);

#endif
