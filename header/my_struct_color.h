/*
** my_struct_color.h for my_struct_color in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 15:29:10 2013 Antoine Plaskowski
** Last update Sun Dec  8 13:32:36 2013 Antoine Plaskowski
*/

#ifndef		MY_STRUCT_COLOR_H_
# define	MY_STRUCT_COLOR_H_

struct		s_color
{
  unsigned char	r;
  unsigned char	v;
  unsigned char	b;
  unsigned char	endian;
};

typedef		struct s_color t_color;

int		my_set_color(t_color *color, unsigned char r,
			     unsigned char v, unsigned char b);
t_color		*my_get_color(char **str);

#endif		/* !MY_STRUCT_COLOR */

