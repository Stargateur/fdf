/*
** test_igraph.c for igraph in /home/favret_m/test
** 
** Made by Maxime Favret
** Login   <favret_m@epitech.net>
** 
** Started on  Thu Oct 24 11:12:01 2013 Maxime Favret
** Last update Thu Oct 24 14:35:34 2013 Maxime Favret
*/

#include "mlx.h"

int	main()
{
  void	*mlx_ptr;
  void	*win_ptr;
  int	x;
  int	y;
  int limit_l;
  int limit_r;

  limit_l = 1430;
  limit_r = 2070;
  x = 1;
  y = 1;
  mlx_ptr = mlx_init();
  win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "test");
  while (y != 1080)
    {
      if (x <= limit_l)
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00088608);
      else if (x > limit_l && x < limit_r)
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FFFF00);
      else
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00FF0000);
      x++;
      if (x == 1920)
	{
	  limit_l -= y % 2 + 1;
	  limit_r -= y % 2 + 1;
	  y++;
	  x = 1;
	}
    }
  usleep(5000000);
}
