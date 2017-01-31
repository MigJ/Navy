/*
** verify.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:30:06 2017 miguel joubert
** Last update Mon Jan 30 23:32:15 2017 miguel joubert
*/

#include "../include/my.h"

void    verify_pos(char *buff)
{
  int   value;

  value = 5;
  (buff[31] != 0) ? exit(1) : 0;
  while (value != 37)
    {
      ((buff[value] - 48) - (buff[value - 3] - 48) == (buff[value - 5] - 49) ||
       (buff[value + 1] - 48) - (buff[value - 2] - 48) == (buff[value - 5] - 49)) ? 0 : exit (1);
      if (buff[value - 3] > 72 || buff[value] > 72 || buff[value - 2] > 56 || buff[value + 1] > 56) exit (1);
      value += 8;
    }
}

t_hit   case_cpy(char *buff, t_hit H)
{
  H.tmp = (buff[H.i + 3] - 48) - (buff[H.i] - 48);
  while (H.pos != H.tmp - 1)
    {
      H.all_case[H.j] = malloc(sizeof(char) * 3);
      H.all_case[H.j][H.k++] = buff[H.i] + H.pos + 1;
      H.all_case[H.j][H.k++] = buff[H.i + 1];
      H.all_case[H.j++][H.k] = 0;
      H.k = 0;
      H.pos++;
    }
  return (H);
}

t_hit   case_cpy_second(char *buff, t_hit H)
{
  H.tmp = buff[H.i + 4] - buff[H.i + 1];
  while (H.pos != H.tmp - 1)
    {
      H.all_case[H.j] = malloc(sizeof(char) * 3);
      H.all_case[H.j][H.k++] = buff[H.i];
      H.all_case[H.j][H.k++] = buff[H.i + 1] + H.pos + 1;
      H.all_case[H.j++][H.k] = 0;
      H.k = 0;
      H.pos++;
    }
  return (H);
}

t_hit   case_cpy_third(char *buff, t_hit H)
{
  H.all_case[H.j] = malloc(sizeof(char) * 3);
  H.all_case[H.j][H.k++] = buff[H.i];
  H.all_case[H.j][H.k++] = buff[H.i + 1];
  H.all_case[H.j++][H.k] = 0;
  H.pos = H.k = 0;
  H.i += (buff[H.i + 2] == '\n') ? 5 : 3;
  H.bol = (H.bol == 0) ? 1 : 0;
  return (H);
}

void    verify_hit(char *buff)
{
  t_hit H;

  H.pos = H.bol = H.j = H.k = 0;
  H.i = 2;
  H.all_case = malloc(sizeof(char *) * 15);
  while (buff[H.i - 2])
    {
      if (buff[H.i] != buff[H.i + 3] && H.bol == 0) H = case_cpy(buff, H);
      else if (buff[H.i + 4] - buff[H.i + 1] != 1 && buff[H.i + 4] - buff[H.i + 1] != 0
	       && H.bol == 0) H = case_cpy_second(buff, H);
      H = case_cpy_third(buff, H);
    }
  H.all_case[H.j] = NULL;
  H.j = 0;
  while (H.all_case[H.j])
    {
      H.k = H.j + 1;
      while (H.all_case[H.k])
	{
	  if (strcmp(H.all_case[H.j], H.all_case[H.k]) == 0) exit (1);
	  H.k++;
	}
      H.j++;
    }
}
