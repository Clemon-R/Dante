/*
** main_gene.c for  in /home/tdebrand/dante/generator/src
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon May  1 15:29:42 2017 Thomas DEBRAND PASSARD
** Last update Fri May  5 20:59:18 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdlib.h>
#include "gen.h"

int	main(int ac, char **av)
{
  t_map	*map;
  char	**tab;

  if (!(map = malloc(sizeof(t_map))))
    return (84);
  map = malloc(sizeof(t_map));
  map->height =	my_getnbr(av[2]);
  map->width = my_getnbr(av[1]);
  gen(map);
  return (0);
}
