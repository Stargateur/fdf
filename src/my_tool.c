/*
** my_tool.c for my_tool in /home/plasko_a/rendu/MUL_2013_fdf
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 10:54:05 2013 Antoine Plaskowski
** Last update Sun Dec  8 12:57:48 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my_struct_data.h"
#include	"my.h"

int		my_nbr_is_nhexa(const char **str)
{
  int		i;

  if (str == NULL || *str == NULL)
    return (1);
  (*str)++;
  if (*(*str)++ != '0' || *(*str)++ != 'X')
    return (1);
  i = 0;
  while (**str != ' ' && **str != '\0')
    {
      if (my_char_in_str(**str, "0123456789ABCDEF") == -1)
	return (1);
      else
	(*str)++;
      i++;
    }
  if (i > 6 || i % 2)
    return (1);
  return (0);
}

int		my_nbr_of_nbr(const char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (*str)
    {
      while (*str == ' ' || *str == '-' || *str == '+')
	str++;
      if (*str >= '0' && *str <= '9')
	i++;
      else
	return (-1);
      while (*str >= '0' && *str <= '9')
	str++;
      if (*str == ',')
	if (my_nbr_is_nhexa(&str))
	  return (-1);
    }
  return (i);
}

int		my_size_check(const t_data *data)
{
  int		size;

  if (data == NULL)
    return (1);
  size = data->size;
  while (data != NULL)
    {
      if (size != data->size)
	return (2);
      data = data->next;
    }
  return (0);
}
