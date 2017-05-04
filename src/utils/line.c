/*
** line.c for default in /home/raphael.goulmot/corewar
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.eu>
** 
** Started on  Thu Mar 30 20:20:06 2017 Raphaël Goulmot
** Last update Sat Apr  1 00:35:34 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    end_line(t_read *world)
{
  char  end;

  end = world->buff && my_strlen(world->buff) ? 1 : -1;
  if (end == -1)
    free_buff(&world->buff);
  return (end);
}

char	*read_buff(const int fid, t_read *world)
{
  int	len;

  world->buff = malloc(sizeof(char) * (READ_SIZE + 1));
  len = read(fid, world->buff, READ_SIZE);
  world->buff[len] = 0;
  world->index = 0;
  return (world->buff);
}

char	*add_text(char *line, t_read *world)
{
  int	size;
  char	*str;
  int	i;
  int	i1;

  i = i1 = 0;
  size = my_strlen(world->buff);
  str = malloc(sizeof(char) * ((line ? my_strlen(line) : 0) + size + 1));
  if (!str)
    return (line);
  while (line && line[i1])
    str[i++] = line[i1++];
  while (world->buff && world->buff[world->index]
	 && world->buff[world->index] != '\n')
    str[i++] = world->buff[world->index++];
  str[i] = 0;
  if (line)
    free_buff(&line);
  return (str);
}

void	free_buff(char **str)
{
  if (*str)
    {
      free(*str);
      *str = 0;
    }
}

char	*get_next_line(const int fid)
{
  static t_read	world;
  char		*str;

  if (world.old_fid != fid && world.buff)
    free_buff(&world.buff);
  if (!(str = 0) && fid < 0)
    return (0);
  else if (!world.buff)
    read_buff(fid, &world);
  while (world.buff && end_line(&world) == 1)
    {
      str = add_text(str, &world);
      if (world.buff[world.index] == '\n')
	break;
      else if (!world.buff[world.index])
	free_buff(&world.buff);
      if (!world.buff)
	read_buff(fid, &world);
    }
  if (world.buff && world.buff[world.index] == '\n')
    world.index++;
  if (world.buff && world.buff[world.index] == 0)
    free_buff(&world.buff);
  world.old_fid = fid;
  return (str);
}
