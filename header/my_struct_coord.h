/*
** my_struct_coord.h for my_struct_coord in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Nov 21 09:02:53 2013 Antoine Plaskowski
** Last update Thu Dec  5 15:30:46 2013 Antoine Plaskowski
*/

#ifndef		MY_STRUCT_COORD_H_

# define	MY_STRUCT_COORD_H_

# include	"my_struct_color.h"

struct		s_coord
{
  int		x;
  int		y;
  int		z;
  t_color	*color;
};

typedef		struct s_coord t_coord;

int		my_aff_coord(t_coord *coord);
int		my_coord_minus_coord(t_coord *coord, t_coord *a, t_coord *b);
t_coord		*my_new_coord(int x, int y, int z, t_color *color);
t_coord		**my_create_coord(char *str, const int size, const int i);
int		my_set_coord(t_coord *coord, int x, int y, int z);

#endif		/* !MY_STRUCT_COORD_H_ */
