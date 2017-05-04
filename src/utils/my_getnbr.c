/*
** my_getnbr.c for default in /home/raphael.goulmot/default_struct
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Dec 16 15:20:37 2016 Raphaël Goulmot
** Last update Thu May  4 13:00:07 2017 Raphaël Goulmot
*/

#include "utils.h"

int	my_getnbr(char *str)
{
  char	*clone;
  char	neg;
  int	value;

  clone = str;
  while (clone && *clone && (*clone == '-' || *clone == '+') && ++clone);
  neg = str != clone ? *(clone - 1) == '-' : *clone == '-';
  value = 0;
  while (clone && *clone >= '0' && *clone <= '9' && ++clone)
    value = value * 10 + (*(clone - 1) - 48);
  return (value * (neg ? -1 : 1));
}
