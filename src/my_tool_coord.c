/*
** my_tool_coord.c for my_tool_coord in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Nov 27 00:36:01 2013 Antoine Plaskowski
** Last update Sun Dec  8 13:43:34 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_struct_coord.h"
#include	"my.h"

int		my_swap_coord(t_coord **ptr1, t_coord **ptr2)
{
  t_coord	*tmp;

  if (ptr1 == NULL || ptr2 == NULL)
    return (1);
  tmp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = tmp;
  return (0);
}

t_coord		*my_cpy_coord(t_coord *coord)
{
  t_coord	*cpy;

  if (coord == NULL)
    return (NULL);
  if ((cpy = my_malloc(sizeof(t_coord))) == NULL)
    return (NULL);
  if ((cpy->color = my_malloc(sizeof(t_coord))) == NULL)
    return (NULL);
  cpy->x = coord->x;
  cpy->y = coord->y;
  cpy->z = coord->z;
  cpy->color->r = coord->color->r;
  cpy->color->b = coord->color->b;
  cpy->color->v = coord->color->v;
  return (cpy);
}

void		my_free_coord(t_coord *coord)
{
  if (coord != NULL)
    free(coord->color);
  free(coord);
}

int		my_norm_coord(t_coord *a, t_coord *b)
{
  int		norm_a;
  int		norm_b;

  if (a == NULL || b == NULL)
    return (0);
  norm_a = my_power_rec((b->x - a->x), 2);
  norm_b = my_power_rec((b->y - a->y), 2);
  return (my_square_root(norm_a + norm_b));
}
