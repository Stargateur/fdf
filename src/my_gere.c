/*
** my_gere.c for my_gere in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 14:44:45 2013 Antoine Plaskowski
** Last update Sun Dec  8 16:11:06 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"mlx.h"
#include	"main.h"
#include	"my_move.h"
#include	"my_control.h"

int		my_gere_expose(t_mlx_ptr *mlx_ptr)
{
  mlx_put_image_to_window(mlx_ptr->ini, mlx_ptr->win, mlx_ptr->img, 0, 0);
  return (0);
}

int		my_gere_mouse(int button, int x, int y, t_mlx_ptr *mlx_ptr)
{
  if (button == 1)
    {
      mlx_ptr->origin_x = x - SIZE_X / 2;
      mlx_ptr->origin_y = y;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  return (0);
}

int		my_gere_key(int key, t_mlx_ptr *mlx_ptr)
{
  if (key == 65307)
    {
      mlx_destroy_window(mlx_ptr->ini, mlx_ptr->win);
      my_free_data(mlx_ptr->data);
      exit(0);
    }
  else
    my_move_down(mlx_ptr, key);
  return (0);
}
