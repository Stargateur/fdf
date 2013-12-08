/*
** my_abs.c for my_abs in /home/plasko_a/rendu/Piscine-C-lib/my
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Nov 24 09:11:39 2013 Antoine Plaskowski
** Last update Sun Nov 24 09:13:29 2013 Antoine Plaskowski
*/

int		my_abs(const int nbr)
{
  if (nbr == -2147483648)
    return (0);
  if (nbr < 0)
    return (-nbr);
  return (nbr);
}
