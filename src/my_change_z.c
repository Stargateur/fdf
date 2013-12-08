/*
** my_change_z.c for my_change_z in /home/plasko_a/rendu/MUL_2013_fdf/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec  8 14:11:52 2013 Antoine Plaskowski
** Last update Sun Dec  8 16:18:53 2013 Antoine Plaskowski
*/

#include	"main.h"
#include	"my_control.h"
#include	"my_gere.h"
#include	"my_change_deca.h"

int		my_up_z(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65451)
    {
      mlx_ptr->deca_z += 0.05;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_deca_down_y(mlx_ptr, key);
  return (0);
}

int		my_down_z(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 65453)
    {
      mlx_ptr->deca_z -= 0.05;
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  else
    my_up_z(mlx_ptr, key);
  return (0);
}
