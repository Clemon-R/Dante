/*
** my_base.c for default in /home/raphael.goulmot/new_printf
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Apr 28 17:49:59 2017 Raphaël Goulmot
** Last update Fri Apr 28 18:17:38 2017 Raphaël Goulmot
*/

#include "utils.h"

void    my_put_nbr_base(int nbr, char *base)
{
  int	size;

  size = my_strlen(base);
  if (nbr < 0)
    my_putchar('-');
  nbr = nbr < 0 ? nbr * -1 : nbr;
  if (nbr > size - 1)
    my_put_nbr_base(nbr / size, base);
  my_putchar(base[nbr % size]);
}
