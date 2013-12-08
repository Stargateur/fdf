/*
** my_move.c for move in /home/plasko_a/rendu/MUL_2013_fdf/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec  8 13:10:12 2013 Antoine Plaskowski
** Last update Sun Dec  8 16:15:44 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"mlx.h"
#include	"main.h"
#include	"my_move.h"
#include	"my_control.h"
#include	"my_gere.h"
#include	"my_change_z.h"

int		my_move_left(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65430)
    {
      mlx_ptr->origin_x -= 50;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_down_z(mlx_ptr, key);
  return (0);
}

int		my_move_up(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65431)
    {
      mlx_ptr->origin_y -= 50;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_move_left(mlx_ptr, key);
  return (0);
}

int		my_move_right(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65432)
    {
      mlx_ptr->origin_x += 50;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_move_up(mlx_ptr, key);
  return (0);
}

int		my_move_down(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65433)
    {
      mlx_ptr->origin_y += 50;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_move_right(mlx_ptr, key);
  return (0);
}
