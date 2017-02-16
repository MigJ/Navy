/*
** verify_bis.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 22:09:28 2017 miguel joubert
** Last update Thu Feb 16 19:57:00 2017 Joubert Miguel
*/

#include "../include/my.h"

char	**double_case(char **all_cases)
{
  int	i;
  int	d_i;
  char	**dest;

  i = d_i = 0;
  if ((dest = malloc(sizeof(char *) * 70)) == NULL)
    return (NULL);
  if (*all_cases == NULL) return (NULL);
  while (all_cases[i + 1])
    {
      if (strcmp(all_cases[i], all_cases[i + 1]) == 0) i++;
      else
	{
	  if ((dest[d_i] = malloc(sizeof(char) * 3)) == NULL)
	    return (NULL);
	  dest[d_i] = strcpy(dest[d_i], all_cases[i]);
	  i++, d_i++;
	}
    }
  if (i == 0) return (all_cases);
  dest[d_i++] = all_cases[i];
  dest[d_i] = NULL;
  return (dest);
}

int	is_played(char **all_cases)
{
  static int	i;
  int	j;

  i = 0;
  j = 1;
  if (*all_cases == NULL) return (0);
  while (all_cases[i])
    {
      while (all_cases[j])
	{
	  if (strcmp(all_cases[i], all_cases[j]) == 0)
	    return (1);
	  else
	    j++;
	}
      i++;
      j = i + 1;
    }
  return (0);
}

  int	verify_pos(char *buff)
  {
    int   value;

    if (*buff == 0) return (0);
    value = 5;
    if (buff[31] != 0) return (1);
    while (value != 37)
      {
	if ((buff[value] - 48) - (buff[value - 3] - 48)
	    != (buff[value - 5] - 49) &&
	    (buff[value + 1] - 48) - (buff[value - 2] - 48)
	    != (buff[value - 5] - 49))
	  return (1);
	if (buff[value - 3] > 72 || buff[value] > 72 ||
	    buff[value - 2] > 56 || buff[value + 1] > 56) return (1);
	value += 8;
      }
    return (0);
  }

  int	verify_exist(char *buff)
  {
    if (buff == NULL)
      {
	my_putstr("wrong position\n", 1);
	my_putstr("attack: ", 1);
	return (1);
      }
    else if (*buff == 0 || buff[1] == 0
	     || *buff == ' ' || buff[1] == ' '
	     || buff[2] != 0)
      {
	my_putstr("wrong position\n", 1);
	my_putstr("attack: ", 1);
	return (1);
      }
    buff = pars_case(buff);
    if (*buff > 'H' || *buff < 'A' || buff[1] < '1' || buff[1] > '8')
      {
	my_putstr("wrong position\n", 1);
	my_putstr("attack: ", 1);
	return (1);
      }
    return (0);
  }
