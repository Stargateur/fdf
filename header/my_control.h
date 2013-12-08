/*
** my_control.h for my_control in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 13:29:25 2013 Antoine Plaskowski
** Last update Sun Dec  8 15:55:47 2013 Antoine Plaskowski
*/

#ifndef		MY_CONTROL_H_
# define	MY_CONTROL_H_

# include	"main.h"
# include	"my_struct_data.h"

int		my_clean_win(t_mlx_ptr *mlx_ptr);
int		my_create_img(t_mlx_ptr *mlx_ptr);
int		my_control_master(t_mlx_ptr *mlx_ptr);
int		my_define_deca(t_mlx_ptr *mlx_ptr);

#endif		/* !MY_CONTROL_H_ */
