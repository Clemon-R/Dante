/*
** main.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Apr 28 19:07:46 2017 Raphaël Goulmot
** Last update Sat May  6 17:15:08 2017 Raphaël Goulmot
*/

#include "breadth.h"

int	main(int argc, char **argv)
{
  if (argc == 2)
    breadth(argv[1]);
  return (0);
}
