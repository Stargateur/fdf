/*
** main.h for tp1 in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 18:45:32 2013 Antoine Plaskowski
** Last update Sun Dec  8 15:37:39 2013 Antoine Plaskowski
*/

#ifndef		MAIN_H_
# define	MAIN_H_

# define	SIZE_X	1900
# define	SIZE_Y	1000
# define	DECA_X	8
# define	DECA_Y	4
# define	DECA_Z	0.5

# include	"my_struct_data.h"

struct		s_mlx_ptr
{
  void		*ini;
  void		*win;
  void		*img;
  int		origin_x;
  int		origin_y;
  double	k_x;
  double	k_y;
  double	deca_x;
  double	deca_y;
  double	deca_z;
  t_data	*data;
};

typedef		struct s_mlx_ptr t_mlx_ptr;

#endif		/* !MAIN_H_ */
