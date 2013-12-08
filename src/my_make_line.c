/*
** my_make_line.c for my_make_line in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 09:31:48 2013 Antoine Plaskowski
** Last update Sun Dec  8 16:02:47 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"main.h"
#include	"my_put_pixel_in_img.h"
#include	"my_struct_color.h"
#include	"my_struct_coord.h"
#include	"my_tool_coord.h"
#include	"mlx.h"
#include	"my.h"

int		my_line_error(t_coord *a, t_coord *incre, t_coord *d, int *e)
{
  int		tmp;

  if (a == NULL || incre == NULL || d == NULL || e == NULL)
    return (1);
  tmp = *e * 2;
  if (tmp > -d->y)
    {
      *e -= d->y;
      a->x += incre->x;
    }
  if (tmp < d->x)
    {
      *e += d->x;
      a->y += incre->y;
    }
  return (0);
}

int		my_define_incre(t_coord *incre, t_coord *a, t_coord *b)
{
  if (incre == NULL || a == NULL || b == NULL)
    return (1);
  if (a->x < b->x)
    incre->x = 1;
  else
    incre->x = -1;
  if (a->y < b->y)
    incre->y = 1;
  else
    incre->y = -1;
  incre->z = 0;
  return (0);
}

int		my_degra_color(t_color *degra, t_coord *a, t_coord *b, int norm)
{
  int		cur_norm;
  int		tmp;

  if (degra == NULL || a == NULL || b == NULL)
    return (1);
  if (a->color != NULL && b->color != NULL)
    {
      cur_norm = my_norm_coord(a, b);
      tmp = a->color->r * (cur_norm * 100 / norm) / 100;
      tmp += b->color->r * (100 - cur_norm * 100 / norm) / 100;
      degra->r = tmp;
      tmp = a->color->b * (cur_norm * 100 / norm) / 100;
      tmp += b->color->b * (100 - cur_norm * 100 / norm) / 100;
      degra->b = tmp;
      tmp = a->color->v * (cur_norm * 100 / norm) / 100;
      tmp += b->color->v * (100 - cur_norm * 100 / norm) / 100;
      degra->v = tmp;
    }
  else
    if (my_set_color(degra, 255, 255, 255))
      return (1);
  return (0);
}

int		my_draw_line(t_mlx_ptr *mlx_ptr, t_coord *a, t_coord *b, int norm)
{
  t_color	degra;
  t_coord	d;
  t_coord	incre;
  int		e;

  if (mlx_ptr == NULL || a == NULL || b == NULL)
    return (1);
  d.x = my_abs(b->x - a->x);
  d.y = my_abs(b->y - a->y);
  e = d.x - d.y;
  if (my_define_incre(&incre, a, b))
    return (1);
  while (a->x != b->x || a->y != b->y)
    {
      if (my_degra_color(&degra, a, b, norm))
	return (1);
      if ((a->x >= 0 && a->x < SIZE_X) && (a->y >= 0 && a->y < SIZE_Y))
	my_put_pixel_in_img(mlx_ptr->img, a, &degra);
      my_line_error(a, &incre, &d, &e);
    }
  return (0);
}

int		my_make_line(t_mlx_ptr *m_p, t_coord *a, t_coord *b)
{
  t_coord	*cpy_a;
  t_coord	*cpy_b;

  if (m_p == NULL || a == NULL || b == NULL)
    return (1);
  if ((cpy_a = my_cpy_coord(a)) == NULL || (cpy_b = my_cpy_coord(b)) == NULL)
    return (1);
  cpy_a->x = m_p->origin_x;
  cpy_a->x += (a->x * m_p->k_x + a->y * m_p->k_y) * m_p->deca_x;
  cpy_a->y = m_p->origin_y;
  cpy_a->y += (-a->z * m_p->deca_z - a->x * m_p->k_x + a->y * m_p->k_y)
    * m_p->deca_y;
  cpy_b->x = m_p->origin_x;
  cpy_b->x += (b->x * m_p->k_x + b->y * m_p->k_y) * m_p->deca_x;
  cpy_b->y = m_p->origin_y;
  cpy_b->y += (-b->z * m_p->deca_z - b->x * m_p->k_x + b->y * m_p->k_y)
    * m_p->deca_y;
  my_draw_line(m_p, cpy_a, cpy_b, my_norm_coord(cpy_a, cpy_b));
  my_free_coord(cpy_a);
  my_free_coord(cpy_b);
  return (0);
}
