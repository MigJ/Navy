/*
** verify_bis.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 22:09:28 2017 miguel joubert
** Last update Mon Feb  6 15:32:40 2017 miguel joubert
*/

#include "my.h"

int	is_played(char **all_cases)
{
  int	i;
  int	j;

  i = 0;
  j = 1;
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
  buff = pars_map(buff);
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
  buff = pars_case(buff);
  if (*buff > 'H' || buff[1] > '8' ||
      *buff == 0 || buff[1] == 0 || *buff == ' ')
    {
      my_putstr("wrong position\n", 2);
      my_putstr("attack:  ", 1);
      return (1);
    }
  return (0);
}
