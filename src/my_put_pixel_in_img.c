/*
** my_put_pixel_in_img.c for my_put_pixel_in_img in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 17:39:21 2013 Antoine Plaskowski
** Last update Thu Dec  5 16:01:09 2013 Antoine Plaskowski
*/

#include <stdlib.h>
#include "main.h"
#include "mlx.h"
#include "my_struct_coord.h"
#include "my_struct_color.h"

int             my_put_pixel_in_img(void *img, t_coord *coord, t_color *color)
{
  int           bpp;
  int           sizeline;
  int           endian;
  char		*data;

  if (img == NULL || coord == NULL || color == NULL)
    return (1);
  if ((data = mlx_get_data_addr(img, &bpp, &sizeline, &endian)) == NULL)
    return (2);
  data[coord->y * sizeline + coord->x * 4] = color->b;
  data[coord->y * sizeline + coord->x * 4 + 1] = color->v;
  data[coord->y * sizeline + coord->x * 4 + 2] = color->r;
  data[coord->y * sizeline + coord->x * 4 + 3] = endian;
  return (0);
}
