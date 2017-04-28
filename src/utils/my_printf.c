/*
** my_printf.c for default in /home/raphael.goulmot/new_printf
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Fri Apr 28 17:28:24 2017 Raphaël Goulmot
** Last update Fri Apr 28 18:18:24 2017 Raphaël Goulmot
*/

#include "utils.h"
#include <stdarg.h>
#include <stdlib.h>

static void	ptrsFunction(char c, va_list ap, char *arg, char arg2)
{
  int		value;

  if (c == 'c')
    my_putchar(va_arg(ap, int));
  else if (c == 's' || c == 'S')
    (c == 's' ? my_putstr : my_putstr_upper)(va_arg(ap, char *));
  else if (c == 'i'|| c == 'd' || c == 'b' || c == 'u'
	   || c == 'o' || c == 'x' || c == 'X')
    {
      value = va_arg(ap, int);
      if (c != 'i' && c != 'u' && c != 'd')
	my_put_nbr_base(value, arg);
      else if (c != 'u' || value >= 0)
	my_put_nbr_printf(value, c == 'i' && arg2 == '+');
    }
  else
    my_putchar('%');
}

static char	*option_flag_printf(char **str)
{
  char		*clone;
  char		base;

  clone = *str;
  base = 0;
  while (my_char_isnumeric(*clone) || *clone == '+' || *clone == '#')
    if (*clone++ == '#')
      base = 1;
  if ((*clone == 'x' || *clone == 'X' || *clone == 'o') && base)
    my_putchar('0');
  if (*clone != 'o' && base)
    my_putchar(*clone);
  *str = clone;
  return (*clone == 'o' ? "01234567" : *clone == 'x' ? "0123456789abcdef"
	  : *clone == 'X' ? "0123456789ABCDEF" : "");
}

void    my_printf(char  *str, ...)
{
  va_list       ap;

  if (str == 0)
    return;
  va_start(ap, str);
  while (str && *str)
    {
      if (*str == '%' && *(str + 1))
	{
	  str++;
	  ptrsFunction(*str, ap, option_flag_printf(&str), *str);
	}
      else
	my_putchar(*str);
      str++;
    }
  va_end(ap);
}
