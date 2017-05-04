/*
** main.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Apr 28 19:07:46 2017 Raphaël Goulmot
** Last update Mon May  1 16:06:44 2017 Raphaël Goulmot
*/

#include "astar.h"

int	main(int argc, char **argv)
{
  if (argc == 2)
    astar(argv[1]);
  return (0);
}
