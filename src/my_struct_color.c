/*
** my_struct_color.c for my_struct_color in /home/plasko_a/Documents/PROJET/tp2
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov 12 15:27:20 2013 Antoine Plaskowski
** Last update Sun Dec  8 13:43:01 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_struct_color.h"
#include	"my.h"

int		my_set_color(t_color *color, unsigned char r,
			     unsigned char v, unsigned char b)
{
  if (color == NULL)
    return (1);
  color->r = r;
  color->v = v;
  color->b = b;
  return (0);
}

t_color		*my_get_color(char **str)
{
 t_color	*color;
 int		color_h;

  if (str == NULL || *str == NULL ||
      (color = my_malloc(sizeof(t_color))) == NULL)
    return (NULL);
  if (**str == ',')
    {
      *str = *str + 3;
      color_h = my_getnbr_base(*str, "0123456789ABCDEF");
      color->r = color_h / my_power_rec(16, 4);
      color->v = color_h / my_power_rec(16, 2);
      color->b = color_h % 256;
      while (my_char_in_str(**str, "0123456789ABCDEF") != -1)
	(*str)++;
    }
  else
    if (my_set_color(color, 255, 255, 255))
      return (NULL);
  return (color);
}
