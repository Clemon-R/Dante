/*
** direction.c for  in /home/tdebrand/dante/generator/src
** 
** Made by Thomas DEBRAND PASSARD
** Login   <tdebrand@epitech.net>
** 
** Started on  Tue May  2 15:09:44 2017 Thomas DEBRAND PASSARD
** Last update Thu May  4 19:39:54 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "gen.h"

/*char	**if_up(char **tab, t_map *map)
{
  if ((map->x - 2) < 0)
    return (tab);
  else if (tab[map->x - 1][map->y] == 'X' && tab[map->x - 2][map->y] == 'X')
    {
      map->x--;
      tab[map->x][map->y] = '*';
      map->x--;
      tab[map->x][map->y] = '*';
    }
  else if (tab[map->x - 1][map->y] == '*' && tab[map->x - 2][map->y] == '*')
    map->x -= 2;
  return (tab);
}

char	**if_down(char **tab, t_map *map)
{
  if (map->x + 2 > map->height)
    return (tab);
  else if (tab[map->x + 1][map->y] == 'X' && tab[map->x + 2][map->y] == 'X')
    {
      map->x++;
      tab[map->x][map->y] = '*';
      map->x++;
      tab[map->x][map->y] = '*';
    }
  else if (tab[map->x + 1][map->y] == '*' && tab[map->x + 2][map->y] == '*')
    map->x += 2;
  return (tab);
}

char	**if_right(char **tab, t_map *map)
{
  if (map->y + 2 > map->width)
    return (tab);
  else if (tab[map->x][map->y + 1] == 'X' && tab[map->x][map->y + 2] == 'X')
    {
      map->y++;
      tab[map->x][map->y] = '*';
      map->y++;
      tab[map->x][map->y] = '*';
    }
  else if (tab[map->x][map->y + 1] == '*' && tab[map->x][map->y + 2] == '*')
    map->y += 2;
  return (tab);
}

char	**if_left(char **tab, t_map *map)
{
  if (map->y - 2 < 0)
    return (tab);
  else if (tab[map->x][map->y - 1] == 'X' && tab[map->x][map->y - 2] == 'X')
    {
      map->y--;
      tab[map->x][map->y] = '*';
      map->y--;
      tab[map->x][map->y] = '*';
    }
  else if (tab[map->x][map->y - 1] == '*' && tab[map->x][map->y - 2] == '*')
    map->y -= 2;
  return (tab);
}
*/
