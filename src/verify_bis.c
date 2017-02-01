/*
** verify_bis.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 22:09:28 2017 miguel joubert
** Last update Wed Feb  1 22:10:35 2017 miguel joubert
*/

#include "../include/my.h"

int    verify_pos(char *buff)
{
  int   value;

  if (buff == NULL || *buff == 0) return (0);
  value = 5;
  if (buff[31] != 0) return (1);
  while (value != 37)
    {
      if ((buff[value] - 48) - (buff[value - 3] - 48) != (buff[value - 5] - 49) &&
	  (buff[value + 1] - 48) - (buff[value - 2] - 48) != (buff[value - 5] - 49))
	return (1);
      if (buff[value - 3] > 72 || buff[value] > 72 ||
	  buff[value - 2] > 56 || buff[value + 1] > 56) return (1);
      value += 8;
    }
  return (0);
}

int     verify_exist(char *buff)
{
  buff = pars_case(buff);
  if (*buff > 'H' || buff[1] > '8' || *buff == 0 || buff[1] == 0 || *buff == ' ')
    {
      my_putstr("wrong position\n", 2);
      my_putstr("attack:  ", 1);
      return (1);
    }
  return (0);
}
