/*
** main.c for tp1 in /home/plasko_a/Documents/PROJET/tp1minilib
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Tue Nov  5 14:11:49 2013 Antoine Plaskowski
** Last update Sun Dec  8 16:45:19 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	"main.h"
#include	"mlx.h"
#include	"my_control.h"
#include	"my_struct_data.h"
#include	"my.h"

int		main(int argc , char **argv)
{
  t_mlx_ptr	mlx_ptr;
  int		fd;

  if (argc < 1)
    {
      my_putstr("Usage ./fdf file\n", 2);
      return (1);
    }
  if ((fd = open(argv[1], O_RDONLY)) < 0)
    {
      perror(argv[1]);
      return (1);
    }
  if ((mlx_ptr.data = my_create_data(fd)) == NULL)
    {
      my_putstr("File is a lie\n", 2);
      close(fd);
      return (1);
    }
  close(fd);
  if ((mlx_ptr.ini = mlx_init()) == NULL)
    return (1);
  my_control_master(&mlx_ptr);
  return (0);
}
