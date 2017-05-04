/*
** utils.h for default in /home/raphael.goulmot/default_struct
**
** Made by Raphaël Goulmot
** Login   <raphael.goulmot@epitech.net>
**
** Started on  Thu Dec 15 14:35:14 2016 Raphaël Goulmot
** Last update Mon May  1 16:03:20 2017 Thomas DEBRAND PASSARD
*/

#ifndef UTILS_H_
# define UTILS_H_

# include <stdarg.h>

void	my_putchar(char);
void	my_putstr(char *);
void	my_putstr_upper(char *);
void	my_putstr_err(char *);
int	my_strlen(char *);
int	my_strstrlen(char **);
int	my_getnbr(char *);
void	my_put_nbr(int);
char	my_char_islower(char);
char	my_char_isupper(char);
char	my_char_isalpha(char);
char	my_char_isnumeric(char);
char	my_str_isnumeric(char *);
int	length_word(char *, int, char);
int	count_words(char *, char);
char	**split(char *, char);
char	*my_strcpy(char *, char *);
char	my_strstr(char *, char *);
char	my_strcmp(char *, char *);
void	free_wordtab(void **);
void	free_safe(void *);
void	my_put_nbr_printf(int, char);
void	my_put_nbr_base(int, char *);
void	my_printf(char *, ...);
void	my_put_tab(char **);

#endif /* !UTILS_H_ */
