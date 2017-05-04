/*
** main_gene.c for  in /home/tdebrand/dante/generator/src
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Mon May  1 15:29:42 2017 Thomas DEBRAND PASSARD
** Last update Thu May  4 15:00:18 2017 Thomas DEBRAND PASSARD
*/

#include "utils.h"
#include "gen.h"

int	main(int ac, char **av)
{
  t_map	*map;
  char	**tab;

  if (!(map = malloc(sizeof(t_map))))
    return (84);
  map->height =	my_getnbr(av[1]);
  map->width = my_getnbr(av[2]);
  map->height -= 1;
  map->width -= 1;
  tab = create_tab(av);
  tab = finish_tab(tab, map);
  my_put_tab(tab);
}
