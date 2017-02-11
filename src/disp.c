/*
** tools_bis.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Sat Feb 11 17:31:14 2017 miguel joubert
** Last update Sat Feb 11 17:52:10 2017 miguel joubert
*/

#include "../include/my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str, int output)
{
  int   i;

  i = 0;
  while (str[i])
    {
      write(output, &str[i], 1);
      i++;
    }
}

void	my_put_nbr(int nb)
{
  int   mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
	  nb = (nb - mod) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + mod);
	}
      else
	my_putchar(48 + nb % 10);
    }
}
