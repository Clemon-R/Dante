/*
** my_is.c for default in /home/raphael.goulmot/default_struct
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Tue Feb 21 18:49:01 2017 Raphaël Goulmot
** Last update Fri Mar 31 23:21:40 2017 Raphaël Goulmot
*/

#include "utils.h"

char	my_char_islower(char c)
{
  return (c >= 'a' && c <= 'z');
}

char	my_char_isupper(char c)
{
  return (c >= 'A' && c <= 'Z');
}

char	my_char_isalpha(char c)
{
  return (my_char_islower(c) || my_char_isupper(c));
}

char	my_char_isnumeric(char c)
{
  return ((c >= '0' && c <= '9') || c == '-');
}

char	my_str_isnumeric(char *str)
{
  char	*clone;

  clone = str;
  while (*clone++)
    if (!my_char_isnumeric(*(clone - 1)))
      return (0);
  return (1);
}
