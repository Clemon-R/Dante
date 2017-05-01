/*
** gen.h for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Sat Apr 29 18:10:59 2017 Raphaël Goulmot
** Last update Mon May  1 14:19:47 2017 Raphaël Goulmot
*/

#ifndef GEN_H_
# define GEN_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct	s_map
{
  char		**map;
  uint		width;
  uint		height;
  bool		perfect;
}		t_map;

char	gen(const uint width, const uint height, const bool perfect);
void	minecraft(const t_map *map);

#endif
