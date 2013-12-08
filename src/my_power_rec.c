/*
** my_power_rec.c for my_power_rec in /home/plasko_a/rendu/Piscine-C-Jour_05
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Fri Oct  4 09:04:23 2013 Antoine Plaskowski
** Last update Thu Dec  5 18:32:37 2013 Antoine Plaskowski
*/

int		my_power_rec(int nb, const int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  return (my_power_rec(nb, power - 1) * nb);
}
