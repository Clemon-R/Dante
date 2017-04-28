/*
** my_putchar.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:07:38 2016 Raphaël Goulmot
** Last update Tue Nov 29 16:08:00 2016 Raphaël Goulmot
*/

#include <unistd.h>
#include "utils.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
