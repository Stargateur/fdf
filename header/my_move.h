/*
** my_move.h for move in /home/plasko_a/rendu/MUL_2013_fdf/header
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec  8 13:16:38 2013 Antoine Plaskowski
** Last update Sun Dec  8 14:18:17 2013 Antoine Plaskowski
*/

#ifndef		MY_MOVE_H_
# define	MY_MOVE_H_

# include	"main.h"

int		my_move_left(t_mlx_ptr *mlx_ptr, int key);
int		my_move_up(t_mlx_ptr *mlx_ptr, int key);
int		my_move_right(t_mlx_ptr *mlx_ptr, int key);
int		my_move_down(t_mlx_ptr *mlx_ptr, int key);

#endif		/* !MY_MOVE_H_ */
