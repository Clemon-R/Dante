/*
** my_putstr.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:08:09 2016 Raphaël Goulmot
** Last update Fri Apr 28 17:55:36 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <unistd.h>

void	my_putstr(char *str)
{
  if (str)
    write(1, str, my_strlen(str));
}

void	my_putstr_upper(char *str)
{
  while (str && *str)
    {
      if (*str >= 'a' && *str <= 'z')
	my_putchar(*str - 32);
      else
	my_putchar(*str);
      str++;
    }
}
