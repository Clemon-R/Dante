/*
** my_purstr_err.c for 102cipher in /home/raphael.goulmot/rendu/102cipher
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Nov 29 16:05:07 2016 Raphaël Goulmot
** Last update Tue Dec 20 15:38:50 2016 Raphaël Goulmot
*/

#include "utils.h"
#include <unistd.h>

void	my_putstr_err(char *str)
{
  write(2, str, my_strlen(str));
}
