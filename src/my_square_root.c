/*
** my_square_root.c for my_square_root in /home/plasko_a/rendu/Piscine-C-Jour_05
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Sun Oct  6 14:34:00 2013 Antoine Plaskowski
** Last update Thu Dec  5 18:10:51 2013 Antoine Plaskowski
*/

int		my_square_root(const int nb)
{
  int		i;

  i = 1;
  while (i * i < nb)
    i++;
  if (i * i == nb)
    return (i);
  return (i - 1);
}
