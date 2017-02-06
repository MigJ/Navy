/*
** verify.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:30:06 2017 miguel joubert
** Last update Mon Feb  6 14:47:19 2017 Nathan Trehout
*/

#include "../include/my.h"

t_hit	init_case(t_hit H)
{
  H.pos = H.bol = H.j = H.k = 0;
  H.i = 2;
  H.all_case = malloc(sizeof(char *) * 30);
  return (H);
}

t_hit	case_cpy(char *buff, t_hit H)
{
  H.tmp = (buff[H.i + 3] - 48) - (buff[H.i] - 48);
  while (H.pos != H.tmp - 1)
    {
      H.all_case[H.j] = malloc(sizeof(char) * 4);
      H.all_case[H.j][H.k++] = buff[H.i] + H.pos + 1;
      H.all_case[H.j][H.k++] = buff[H.i + 1];
      H.all_case[H.j][H.k] = 0;
      H.j++;
      H.k = 0;
      H.pos++;
    }
  return (H);
}

t_hit	case_cpy_second(char *buff, t_hit H)
{
  H.tmp = buff[H.i + 4] - buff[H.i + 1];
  while (H.pos != H.tmp - 1)
    {
      H.all_case[H.j] = malloc(sizeof(char) * 4);
      H.all_case[H.j][H.k++] = buff[H.i];
      H.all_case[H.j][H.k++] = buff[H.i + 1] + H.pos + 1;
      H.all_case[H.j][H.k] = 0;
      H.j++;
      H.k = 0;
      H.pos++;
    }
  return (H);
}

t_hit	case_cpy_third(char *buff, t_hit H)
{
  H.all_case[H.j] = malloc(sizeof(char) * 4);
  H.all_case[H.j][H.k++] = buff[H.i];
  H.all_case[H.j][H.k++] = buff[H.i + 1];
  H.all_case[H.j][H.k] = 0;
  H.j++;
  H.pos = H.k = 0;
  H.i += (buff[H.i + 2] == '\n') ? 5 : 3;
  H.bol = (H.bol == 0) ? 1 : 0;
  return (H);
}

int	verify_hit(char *buff)
{
  t_hit H;

  if (buff == NULL || *buff == 0) return (0);
  H = init_case(H);
  while (H.i != 13)
    {
      if (buff[H.i] != buff[H.i + 3] && H.bol == 0) H = case_cpy(buff, H);
      else if (buff[H.i + 4] - buff[H.i + 1] != 1
	       && buff[H.i + 4] - buff[H.i + 1] != 0
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
	  if (strcmp(H.all_case[H.j], H.all_case[H.k]) == 0) return (1);
	  H.k++;
	}
      H.j++;
    }
  return (0);
}
