/*
** my.h for my in /home/plasko_a/rendu/Piscine-C-include
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Oct 10 11:41:55 2013 Antoine Plaskowski
** Last update Thu Dec  5 18:32:47 2013 Antoine Plaskowski
*/

#ifndef			MY_H_
# define		MY_H_

# include		<stdlib.h>

# define		BUF	4096

struct			s_nline
{
  struct s_nline	*prev;
  char			*str;
  struct s_nline	*next;
};

typedef			struct s_nline t_nline;

char			*get_next_line(const int fd, int reset);

int			my_abs(const int nbr);

void			my_putnbr(int nb, const int fd);

int			my_getnbr(const char *str);

int			my_getnbr_base(const char *str, const char *base);

int			my_square_root(const int nb);

int			my_power_rec(int nb, const int power);

void			my_putchar(const char c, const int fd);

int			my_putstr(const char *str, const int fd);

int			my_strlen(const char *str);

int			my_char_in_str(char c, const char *str);

int			my_strupcase(char *str);

void			*my_malloc(size_t size_octect);

#endif			/* MY_H_ */
