/*
** my_strupcase.c for my_strupcase in /home/plasko_a/rendu/Piscine-C-Jour_06/ex_07
** 
** Made by Antoine Plaskowski
** Login   <plasko_a@epitech.net>
** 
** Started on  Mon Oct  7 16:30:32 2013 Antoine Plaskowski
** Last update Sun Dec  8 13:55:36 2013 Antoine Plaskowski
*/

#include	<stdlib.h>

int		my_strupcase(char *str)
{
  int		i;

  if (str == NULL)
    return (1);
  i = 0;
  while (*(str + i) != '\0')
    {
      if (*(str + i) >= 'a' && *(str + i) <= 'z')
      	*(str + i) = *(str + i) - ('a' - 'A');
      i++;
    }
  return (0);
}
