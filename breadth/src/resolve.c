/*
** resolve.c for astar in /home/raphael.goulmot/rendu/dante
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Mon May  1 16:36:39 2017 Raphaël Goulmot
** Last update Sat May  6 18:24:44 2017 Raphaël Goulmot
*/

#include "breadth.h"
#include "utils.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

t_list	*add_room(t_list *list, t_room *current, t_room *parent)
{
  t_list	*elem;

  elem = malloc(sizeof(t_list));
  if (!elem)
    return (list);
  if (current)
    current->parent = parent;
  elem->get = current;
  elem->next = list;
  return (elem);
}

char	list_contains(t_list *list, t_room *current)
{
  t_room	*elem;

  while (current && list && (elem = list->get))
    {
      if (elem == current)
	return (1);
      list = list->next;
    }
  return (0);
}

t_list	*check_add(t_map *map, t_list *new, t_room *current)
{
  t_room	*tmp;

  tmp = get_room(map, current->y + 1, current->x);
  if (tmp && !tmp->blocked && !list_contains(new, tmp))
    new = add_room(new, tmp, current);
  tmp = get_room(map, current->y - 1, current->x);
  if (tmp && !tmp->blocked && !list_contains(new, tmp))
    new = add_room(new, tmp, current);
  tmp = get_room(map, current->y, current->x + 1);
  if (tmp && !tmp->blocked && !list_contains(new, tmp))
    new = add_room(new, tmp, current);
  tmp = get_room(map, current->y, current->x - 1);
  if (tmp && !tmp->blocked && !list_contains(new, tmp))
    new = add_room(new, tmp, current);
  return (new);
}

void	launch_search(t_map *map, t_list *list)
{
  t_list	*clone;
  t_room	*current;
  char		check;

  clone = list;
  check = 0;
  while (list && (current = list->get))
    {
      if (current == map->end)
	return;
      if (!current->visited)
	{
	  clone = check_add(map, clone, current);
	  check = 1;
	}
      current->visited = true;
      list = list->next;
    }
  if (check)
    launch_search(map, clone);
}

void	resolve(t_map *map)
{
  t_list	*list;
  t_room	*current;

  list = add_room(0, map->start, 0);
  launch_search(map, list);
  current = map->end;
  while (current)
    {
      current->o = true;
      current = current->parent;
    }
  display_map(map);
}
