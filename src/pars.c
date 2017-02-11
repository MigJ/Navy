/*
** pars.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Sat Feb 11 17:22:55 2017 miguel joubert
** Last update Sat Feb 11 17:57:52 2017 miguel joubert
*/

#include "../include/my.h"

t_pars		pars_map_line_loop(t_pars P, char *buff)
{
  P.tmp_i = P.i;
  P.tmp[buff[P.tmp_i] - 48] = malloc(sizeof(char) * 10);
  while (P.i != P.tmp_i + 7)
    P.tmp[buff[P.tmp_i] - 48][P.j++] = buff[P.i++];
  P.i++;
  P.tmp[buff[P.tmp_i] - 48][P.j] = '\n';
  P.tmp[buff[P.tmp_i] - 48][++P.j] = 0;
  P.j = 0;
  return (P);
}

char		*pars_map_line(char *buff)
{
  t_pars	P;

  P.i = P.j = P.k = 0;
  P.dest = malloc(sizeof(char) * 32);
  P.tmp = malloc(sizeof(char *) * 10);
  while (P.i != 32)
    P = pars_map_line_loop(P, buff);
  P.tmp[5][7] = 0;
  P.tmp[6] = NULL;
  P.j = 2;
  P.i = 0;
  while (P.tmp[P.j])
    {
      while (P.tmp[P.j][P.k])
	P.dest[P.i++] = P.tmp[P.j][P.k++];
      P.j++;
      P.k = 0;
    }
  P.dest[P.i] = 0;
  return (P.dest);
}

char		*pars_map_lowcase(char *buff)
{
  char		*dest;
  int		i;

  i = 0;
  dest = malloc(sizeof(char) * 32);
  dest = pars_map_line(buff);
  while (dest[i])
    {
      if (dest[i] <= 'z' && dest[i] >= 'a')
	dest[i] -= 32;
      i++;
    }
  return (dest);
}

char		*pars_map_order(char *buff)
{
  t_order	O;

  O.i = 2;
  O.dest = malloc(sizeof(char) * 32);
  O.dest = pars_map_lowcase(buff);
  while (O.i < 27)
    {
      if ((O.dest[O.i] >= '1' && O.dest[O.i] <= '8')
	  && (O.dest[O.i + 1] >= 'A' && O.dest[O.i + 1] <= 'Z'))
	{
	  O.tmp = O.dest[O.i];
	  O.dest[O.i] = O.dest[O.i + 1];
	  O.dest[O.i + 1] = O.tmp;
	}
      if ((O.dest[O.i + 3] >= '1' && O.dest[O.i + 3] <= '8')
	  && (O.dest[O.i + 4] >= 'A' && O.dest[O.i + 4] <= 'Z'))
	{
	  O.tmp = O.dest[O.i + 3];
	  O.dest[O.i + 3] = O.dest[O.i + 4];
	  O.dest[O.i + 4] = O.tmp;
	}
      O.i += 8;
    }
  return (O.dest);
}

char		*pars_map(char *buff)
{
  char		*dest;
  char		tmp;
  int		i;

  i = 2;
  dest = malloc(sizeof(char) * 32);
  dest = pars_map_order(buff);
  while (i < 27)
    {
      if (dest[i] > dest[i + 3])
	{
	  tmp = dest[i];
	  dest[i] = dest[i + 3];
	  dest[i + 3] = tmp;
	}
      if (dest[i + 1] > dest[i + 4])
	{
	  tmp = dest[i + 1];
	  dest[i + 1] = dest[i + 4];
	  dest[i + 4] = tmp;
	}
      i += 8;
    }
  return (dest);
}
