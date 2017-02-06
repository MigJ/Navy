/*
** maps.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:42:57 2017 miguel joubert
** Last update Mon Feb  6 12:16:14 2017 miguel joubert
*/

#include "include/my.h"

t_vector	convert_co_char(char *number)
{
  t_vector	C;
  int	i;
  char  letter[] = " |A B C D E F G H";
  char  nb[] = " -12345678";

  i = -1;
  if (number == NULL)
    {
      C.x = 0;
      C.y = 0;
      return (C);
    }
  while (letter[++i])
    if (letter[i] == *number)
      {
	C.x = i;
	break;
      }
  i = -1;
  while (nb[++i])
    if (nb[i] == number[1])
      {
	C.y = i;
	break;
      }
  return (C);
}

t_vector	convert_co_int(int x, int y)
{
  t_vector	C;
  int	i;
  char	letter[] = " |A B C D E F G H";
  char	nb[] = " -12345678";

  i = 0;
  while (letter[i])
    {
      if (x + 64 == letter[i++])
	{
	  C.x = i - 1;
	  break;
	}
    }
  i = 0;
  while (nb[i])
    {
      if (y + 48 == nb[i++])
	{
	  C.y = i - 1;
	  break;
	}
    }
  return (C);
}

void	my_disp_map(char **map)
{
  int	i;

  i = 0;
  while (map[i])
    my_putstr(map[i++], 1);
}

char	**my_init_map()
{
  char	**map;
  int	i;

  i = 0;
  map = malloc(sizeof(char *) * 11);
  while (i != 11)
    map[i++] = malloc(sizeof(char) * 18);
  *map = strdup(" |A B C D E F G H\n");
  map[1] = strdup("-+---------------\n");
  i = 2;
  while (i != 10)
    {
      *map[i] = i + 47;
      map[i][1] = '|';
      map[i][2] = 0;
      map[i] = my_strcat(strdup(map[i]), ". . . . . . . .\n\0");
      i++;
    }
  map[i] = NULL;
  return (map);
}

char	**ret_all_cases(char *buff)
{
  t_hit H;

  H.pos = H.bol = H.j = H.k = 0;
  H.i = 2;
  H.all_case = malloc(sizeof(char *) * 15);
  while (H.i != 29)
    {
      if (buff[H.i] != buff[H.i + 3] && H.bol == 0) H = case_cpy(buff, H);
      else if (buff[H.i + 4] - buff[H.i + 1] != 1
	       && buff[H.i + 4] - buff[H.i + 1] != 0
	       && H.bol == 0) H = case_cpy_second(buff, H);
      H = case_cpy_third(buff, H);
    }
  H.all_case[H.j] = NULL;
  return (H.all_case);
}
