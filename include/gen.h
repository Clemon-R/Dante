/*
** gen.h for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr 29 18:10:59 2017 Raphaël Goulmot
** Last update Fri May  5 21:09:34 2017 Raphaël Goulmot
*/

#ifndef GEN_H_
# define GEN_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_room
{
  int		x;
  int		y;
  bool		visited;
  bool		blocked;
  bool		o;
  void		*parent;
}		t_room;

typedef struct	s_map
{
  int		height;
  int		width;
  t_room	*start;
  t_room	*end;
  t_room	***grid;
}		t_map;

//Fichier gen.c
t_room	*create_empty_room(int y, int x);
void	create_empty_grid(t_map *map);
t_room	*next_room(t_map *map, t_room *current);
void	gen(t_map *map);

//Fichier check.c
char	check_arround(t_map *map, t_room *current, char axe);
char	check_h(t_map *map, t_room *current, char dir);
char	check_v(t_map *map, t_room *current, char dir);
char	check_move(t_map *map, t_room *current);

//Fichier move.c
void	display_map(t_map *map);
int	get_random(int a, int b);
t_room	*move_h(t_map *map, t_room *current, char dir);
t_room	*move_v(t_map *map, t_room *current, char dir);

#endif
