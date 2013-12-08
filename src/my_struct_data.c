/*
** my_struct_data.c for my_struct_data in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 10:30:03 2013 Antoine Plaskowski
** Last update Thu Dec  5 15:20:53 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my.h"
#include	"my_struct_data.h"
#include	"my_struct_coord.h"
#include	"my_tool.h"

int		my_aff_data(const t_data *data)
{
  int		i;

  if (data == NULL)
    return (1);
  while (data != NULL)
    {
      i = 0;
      while (i < data->size)
	my_aff_coord(data->coord[i++]);
      data = data->next;
    }
  return (0);
}
int		my_put_data_data(t_data *data, t_coord **coord, int size)
{
  if (data == NULL)
    return (1);
  data->coord = coord;
  data->size = size;
  return (0);
}

int		my_put_data(t_data **data, t_coord **coord, int size)
{
  if (data == NULL)
    return (1);
  if (*data == NULL)
    {
      if ((*data = my_malloc(sizeof(t_data))) == NULL)
	return (2);
      (*data)->prev = NULL;
      (*data)->next = NULL;
      if (my_put_data_data(*data, coord, size))
	return (3);
    }
  else
    {
      if (((*data)->next = my_malloc(sizeof(t_data))) == NULL)
	return (4);
      (*data)->next->prev = *data;
      *data = (*data)->next;
      (*data)->next = NULL;
      if (my_put_data_data(*data, coord, size))
	return (5);
    }
  return (0);
}

t_data		*my_create_data(const int fd)
{
  t_coord	**coord;
  t_data	*data;
  char		*str;
  int		size;
  int		i;

  data = NULL;
  i = 0;
  while ((str = get_next_line(fd, 0)) != NULL)
    {
      if (my_strupcase(str))
	return (NULL);
      if ((size = my_nbr_of_nbr(str)) == -1)
	return (NULL);
      if ((coord = my_create_coord(str, size, i++)) ==  NULL)
	return (NULL);
      if (my_put_data(&data, coord, size))
	return (NULL);
      free(str);
    }
  while (data != NULL && data->prev != NULL)
    data = data->prev;
  if (my_size_check(data))
    return (NULL);
  return (data);
}

int		my_free_data(t_data *data)
{
  t_data	*tmp;
  int		i;

  if (data == NULL)
    return (1);
  while (data->prev != NULL)
    data = data->prev;
  while (data != NULL)
    {
      i = 0;
      if (data->coord != NULL)
	{
	  while (i < data->size)
	    {
	      free(data->coord[i]->color);
	      free(data->coord[i++]);
	    }
	  free(data->coord);
	}
      tmp = data;
      data = data->next;
      free(tmp);
    }
  return (0);
}
