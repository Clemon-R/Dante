/*
** main.c for generator in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Apr 28 19:02:39 2017 Raphaël Goulmot
** Last update Mon May  1 14:08:34 2017 Raphaël Goulmot
*/

#include "gen.h"
#include "utils.h"

int	main(int argc, char **argv)
{
  uint	width;
  uint	height;

  if (argc >= 3 && argc <= 4)
    {
      width = my_getnbr(argv[1]);
      height = my_getnbr(argv[2]);
      gen(width, height, 1);
    }
  return (0);
}
