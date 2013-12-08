/*
** my_change_k.c for my_change_k in /home/plasko_a/rendu/MUL_2013_fdf/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec  8 15:44:07 2013 Antoine Plaskowski
** Last update Sun Dec  8 15:59:52 2013 Antoine Plaskowski
*/

#include	"main.h"
#include	"my_gere.h"
#include	"my_control.h"
#include	"my_reset.h"

int		my_up_k_x(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 100)
    {
      mlx_ptr->k_x += 0.1;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_reset(mlx_ptr, key);
  return (0);
}

int		my_down_k_x(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 113)
    {
      mlx_ptr->k_x -= 0.1;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_up_k_x(mlx_ptr, key);
  return (0);
}

int		my_up_k_y(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 122)
    {
      mlx_ptr->k_y += 0.1;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_down_k_x(mlx_ptr, key);
  return (0);
}

int		my_down_k_y(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 115)
    {
      mlx_ptr->k_y -= 0.1;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_up_k_y(mlx_ptr, key);
  return (0);
}
