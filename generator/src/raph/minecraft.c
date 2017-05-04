/*
** mincraft.c for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 14:12:16 2017 Raphaël Goulmot
** Last update Mon May  1 14:20:56 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "gen.h"
#include <time.h>

static int	get_random(int a, int b)
{
  return (rand()%(b - a + 1) + a);
}

void	minecraft(const t_map *map)
{
  srand(time(0));
  my_printf("Debut du minage...\n");
}
