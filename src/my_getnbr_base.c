/*
** my_getnbr_base.c for my_getnbr_base in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Wed Nov 27 14:55:31 2013 Antoine Plaskowski
** Last update Sun Dec  1 17:35:30 2013 Antoine Plaskowski
*/

#include	<stdlib.h>
#include	"my.h"

int		my_getnbr_base(const char *str, const char *base)
{
  int		signe;
  int		nbr;

  if (str == NULL || base == NULL || my_strlen(base) < 2)
    return (0);
  signe = 1;
  while (*str != '\0' && (*str == '-' || *str == '+'))
    if (*str++ == '-')
      signe *= -1;
  while (*str == '0')
    str++;
  nbr = 0;
  while (my_char_in_str(*str, base) != -1)
    {
      if (signe == 1)
	nbr = nbr * my_strlen(base) + (my_char_in_str(*str++, base));
      else
	nbr = nbr * my_strlen(base) - (my_char_in_str(*str++, base));
      if (nbr != 0 && nbr / nbr != signe / signe)
	return (0);
    }
  return (nbr);
}
