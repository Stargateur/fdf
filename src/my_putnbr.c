/*
** my_put_nbr.c for my_put_nbr in /home/plasko_a/rendu/Piscine-C-Jour_03
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Oct  2 13:24:35 2013 Antoine Plaskowski
** Last update Thu Dec  5 14:32:56 2013 Antoine Plaskowski
*/

#include "my.h"

void		my_putnbr(int nb, const int fd)
{
  if (nb / 10 != 0)
    my_putnbr(nb / 10, fd);
  else if (nb < 0)
    my_putchar('-', fd);
  if ((nb %= 10) < 0)
    nb *= -1;
  my_putchar(nb + '0', fd);
}
