/*
** line.h for default in /home/raphael.goulmot
** 
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
** 
** Started on  Thu Mar 30 20:59:23 2017 Raphaël Goulmot
** Last update Thu May  4 18:22:26 2017 Raphaël Goulmot
*/

#ifndef LINE_H_
# define LINE_H_

# ifndef READ_SIZE
# define READ_SIZE 4096
# endif

typedef struct	s_read
{
  char	*buff;
  int	index;
  int	old_fid;
}		t_read;

char	end_line(t_read *);
void	free_buff(char **);
char	*read_buff(const int, t_read *);
char	*add_text(char *, t_read *);
char	*get_next_line(const int);

#endif
