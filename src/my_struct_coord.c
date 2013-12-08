/*
** my_struct_coord.c for my_struct_coord in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Thu Nov 21 09:02:32 2013 Antoine Plaskowski
** Last update Sun Dec  8 13:46:19 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_struct_coord.h"
#include	"main.h"
#include	"my.h"

int		my_aff_coord(t_coord *coord)
{
  if (coord == NULL)
    return (1);
  my_putchar('(', 1);
  my_putnbr(coord->x, 1);
  my_putchar(',', 1);
  my_putnbr(coord->y, 1);
  my_putchar(',', 1);
  my_putnbr(coord->z, 1);
  my_putstr(")\n", 1);
  return (0);
}

int		my_coord_minus_coord(t_coord *coord, t_coord *a, t_coord *b)
{
  if (coord == NULL || a == NULL || b == NULL)
    return (1);
  coord->x = a->x - b->x;
  coord->y = a->y - b->y;
  coord->z = a->z - b->z;
  return (0);
}

t_coord		*my_new_coord(int x, int y, int z, t_color *color)
{
  t_coord	*coord;

  if ((coord = my_malloc(sizeof(t_coord))) == NULL)
    return (NULL);
  coord->x = x;
  coord->y = y;
  coord->z = z;
  coord->color = color;
  return (coord);
}

t_coord		**my_create_coord(char *str, const int size, const int i)
{
  t_coord	**coord;
  int		j;
  int		nbr;

  if (str == NULL)
    return (NULL);
  if ((coord = my_malloc(sizeof(t_coord *) * size)) == NULL)
    return (NULL);
  j = 0;
  while (j < size && *str)
    {
      while (*str == ' ')
	str++;
      nbr = my_getnbr(str);
      while (*str == '-' || *str == '+')
	str++;
      while (*str >= '0' && *str <= '9')
	str++;
      coord[j] = my_new_coord(j, i, nbr, my_get_color(&str));
      j++;
    }
  return (coord);
}

int		my_set_coord(t_coord *coord, int x, int y, int z)
{
  if (coord == NULL)
    return (1);
  coord->x = x;
  coord->y = y;
  coord->z = z;
  return (0);
}
