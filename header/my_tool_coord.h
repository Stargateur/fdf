/*
** my_tool_coord.h for my_tool_coord in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Nov 27 00:47:20 2013 Antoine Plaskowski
** Last update Sun Dec  8 15:43:27 2013 Antoine Plaskowski
*/

#ifndef		MY_TOOL_COORD_H_
# define	MY_TOOL_COORD_H_

# include	"my_struct_coord.h"

int		my_swap_coord(t_coord **ptr1, t_coord **ptr2);
t_coord		*my_cpy_coord(t_coord *coord);
int		my_norm_coord(t_coord *a, t_coord *b);
void		my_free_coord(t_coord *coord);

#endif		/* !MY_TOOL_COORD_H_ */
