/*
** line.c for default in /home/raphael.goulmot/corewar
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.eu>
** 
** Started on  Thu Mar 30 20:20:06 2017 Raphaël Goulmot
** Last update Thu May  4 17:50:49 2017 Raphaël Goulmot
*/

#include "utils.h"
#include "line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(const int fid)
{
  static t_read	stack;
  char	*line;

  if (fid < 0)
    return (0);
  if (!stack.buff || stack.old_fid != fid)
    stack.buff = read_buff(fid, &stack);
  stack.old_fid = fid;
  line = stack.buff ? add_text(0, 0) : 0;
  while (stack.buff && stack.buff[stack.index]
	 && stack.buff[stack.index] != '\n')
    {
      line = add_text(line, &stack);
      if (!stack.buff[stack.index])
	stack.buff = read_buff(fid, &stack);
    }
  if (stack.buff && stack.buff[stack.index] == '\n')
    stack.index++;
  if (stack.buff && !stack.buff[stack.index])
    free_buff(&stack.buff);
  return (line);
}

char	*read_buff(const int fid, t_read *world)
{
  int	len;

  if (world->buff)
    free(world->buff);
  world->buff = malloc(sizeof(char) * (READ_SIZE + 1));
  len = read(fid, world->buff, READ_SIZE);
  world->buff[len] = 0;
  if (!len)
    free_buff(&world->buff);
  world->index = 0;
  return (world->buff);
}

char	*add_text(char *line, t_read *world)
{
  int	size;
  char	*str;
  int	i;

  i = 0;
  size = 0;
  if (world)
    size = my_strlen(world->buff);
  str = malloc(sizeof(char) * ((line ? my_strlen(line) : 0) + size + 1));
  if (!str)
    return (line);
  while (line && line[i])
    str[i] = line[i++];
  while (world && world->buff && world->buff[world->index]
	 && world->buff[world->index] != '\n')
    str[i++] = world->buff[world->index++];
  str[i] = 0;
  if (line)
    free(line);
  return (str);
}

void	free_buff(char **line)
{
  if (line && *line)
    free(*line);
  *line = 0;
}
