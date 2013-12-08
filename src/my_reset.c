/*
** my_reset.c for my_reset in /home/plasko_a/rendu/MUL_2013_fdf/src
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Dec  8 15:53:33 2013 Antoine Plaskowski
** Last update Sun Dec  8 15:56:31 2013 Antoine Plaskowski
*/

#include	"main.h"
#include	"my_gere.h"
#include	"my_control.h"

int		my_reset(t_mlx_ptr *mlx_ptr, int key)
{
  if (key == 114)
    {
      my_define_deca(mlx_ptr);
      my_clean_win(mlx_ptr);
      my_create_img(mlx_ptr);
      my_gere_expose(mlx_ptr);
    }
  return (0);
}
