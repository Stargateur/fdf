/*
** my_change_deca.c for my_change_deca in /home/plasko_a/rendu/MUL_2013_fdf/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec  8 14:25:39 2013 Antoine Plaskowski
** Last update Sun Dec  8 15:51:25 2013 Antoine Plaskowski
*/

#include	"main.h"
#include	"my_control.h"
#include	"my_gere.h"
#include	"my_change_k.h"

int		my_deca_up_x(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65363)
    {
      mlx_ptr->deca_x++;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_down_k_y(mlx_ptr, key);
  return (0);
}

int		my_deca_down_x(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65361)
    {
      mlx_ptr->deca_x--;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_deca_up_x(mlx_ptr, key);
  return (0);
}

int		my_deca_up_y(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65362)
    {
      mlx_ptr->deca_y++;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_deca_down_x(mlx_ptr, key);
  return (0);
}

int		my_deca_down_y(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65364)
    {
      mlx_ptr->deca_y--;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_deca_up_y(mlx_ptr, key);
  return (0);
}
