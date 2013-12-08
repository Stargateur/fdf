/*
** my_control.c for my_control in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 12:53:08 2013 Antoine Plaskowski
** Last update Sun Dec  8 15:55:19 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"main.h"
#include	"mlx.h"
#include	"my_gere.h"
#include	"my_struct_data.h"
#include	"my_make_line.h"
#include	"my_put_pixel_in_img.h"

int		my_clean_win(t_mlx_ptr *mlx_ptr)
{
  t_coord	coord;
  t_color	color;
  int		i;
  int		j;

  i = 0;
  my_set_color(&color, 0, 0, 0);
  while (i < SIZE_Y)
    {
      j = 0;
      while (j < SIZE_X)
	{
	  coord.x = j;
	  coord.y = i;
	  my_put_pixel_in_img(mlx_ptr->img, &coord, &color);
	  j++;
	}
      i++;
    }
  return (0);
}

int		my_create_img(t_mlx_ptr *mlx_ptr)
{
  int		i;
  t_data	*tmp;

  if (mlx_ptr == NULL || mlx_ptr->data == NULL)
    return (1);
  tmp = mlx_ptr->data;
  while (mlx_ptr->data != NULL)
    {
      i = 0;
      while (i < mlx_ptr->data->size)
	{
	  if (i + 1 < mlx_ptr->data->size)
	    if (my_make_line(mlx_ptr, mlx_ptr->data->coord[i],
			     mlx_ptr->data->coord[i + 1]))
	      return (2);
	  if (mlx_ptr->data->next != NULL)
	    if (my_make_line(mlx_ptr, mlx_ptr->data->coord[i],
			     mlx_ptr->data->next->coord[i]))
	      return (3);
	  i++;
	}
      mlx_ptr->data = mlx_ptr->data->next;
    }
  mlx_ptr->data = tmp;
  return (0);
}

static int	my_define_deca_ans(t_mlx_ptr *mlx_ptr, int max_x, int max_z)
{
  mlx_ptr->deca_x = SIZE_X / (max_x + mlx_ptr->data->size);
  mlx_ptr->deca_y = SIZE_Y / (max_x + mlx_ptr->data->size + max_z * 0.8);
  mlx_ptr->deca_z = 0.5;
  mlx_ptr->origin_x = 0;
  mlx_ptr->origin_y = (SIZE_Y - 1) / 2;
  mlx_ptr->k_x = 1;
  mlx_ptr->k_y = 1;
  return (0);
}

int		my_define_deca(t_mlx_ptr *mlx_ptr)
{
  t_data	*tmp;
  int		j;
  int		max_x;
  int		max_z;

  tmp = mlx_ptr->data;
  max_x = 0;
  max_z = 0;
  while (mlx_ptr->data != NULL)
    {
      j = 0;
      while (j < (mlx_ptr->data)->size)
	{
	  if (mlx_ptr->data->coord[j]->z > max_z)
	    max_z = mlx_ptr->data->coord[j]->z;
	  j++;
	}
      max_x++;
      mlx_ptr->data = mlx_ptr->data->next;
    }
  mlx_ptr->data = tmp;
  my_define_deca_ans(mlx_ptr, max_x, max_z);
  return (0);
}

int		my_control_master(t_mlx_ptr *mlx_ptr)
{
  if (mlx_ptr == NULL || mlx_ptr->data == NULL)
    return (1);
  if (my_define_deca(mlx_ptr))
    return (1);
  if ((mlx_ptr->img = mlx_new_image(mlx_ptr->ini, SIZE_X, SIZE_Y)) == NULL)
    return (2);
  if (my_create_img(mlx_ptr))
    return (2);
  if ((mlx_ptr->win = mlx_new_window(mlx_ptr->ini, SIZE_X, SIZE_Y, "FDF"))
      == NULL)
    return (3);
  mlx_put_image_to_window(mlx_ptr->ini, mlx_ptr->win, mlx_ptr->img, 0, 0);
  mlx_key_hook(mlx_ptr->win, &my_gere_key, mlx_ptr);
  mlx_mouse_hook(mlx_ptr->win, &my_gere_mouse, mlx_ptr);
  mlx_expose_hook(mlx_ptr->win, &my_gere_expose, mlx_ptr);
  mlx_loop(mlx_ptr->ini);
  return (0);
}
