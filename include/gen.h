/*
** gen.h for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr 29 18:10:59 2017 Raphaël Goulmot
** Last update Thu May  4 15:40:33 2017 Thomas DEBRAND PASSARD
*/

#ifndef GEN_H_
# define GEN_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_map
{
  int		height;
  int		width;
  int		x;
  int		y;
}		t_map;

char	gen(const uint width, const uint height, const bool perfect);
void	minecraft(t_map *map);

/*
**	create_tab.c
*/

char	**create_tab(char **);
char	**finish_tab(char **, t_map *);

/*
**	direction.c
*/

char	**if_up(char **, t_map *);
char	**if_down(char **, t_map *);
char	**if_right(char **, t_map *);
char	**if_left(char **, t_map *);

#endif
