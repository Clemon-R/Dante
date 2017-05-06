/*
** astar.h for asatr in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 15:54:44 2017 Raphaël Goulmot
** Last update Sat May  6 18:25:11 2017 Raphaël Goulmot
*/

#ifndef BREADTH_H_
# define BREADTH_H_

# include <stdbool.h>

typedef struct	s_room
{
  int		x;
  int		y;
  bool		o;
  bool		visited;
  bool		blocked;
  struct s_room		*parent;
}		t_room;

typedef struct	s_map
{
  t_room	***grid;
  t_room	*start;
  t_room	*end;
  int		width;
  int		height;
}		t_map;

typedef struct s_list
{
  t_room	*get;
  struct s_list	*next;
}		t_list;

//Fichier solve.c
void	display_map(t_map *map);
void	load_line(char *line, t_room **grid_line, int y);
void	load_map(t_map *amp, int fid);
t_map	*load_file(char *file_name);
void	breadth(char *file_name);

//Fichier resolve.c
void	resolve(t_map *map);

//Fichier get_room.c
t_room	*get_room(t_map *map, int y, int x);

#endif
