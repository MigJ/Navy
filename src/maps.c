/*
** maps.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:42:57 2017 miguel joubert
** Last update Tue Jan 31 02:18:56 2017 miguel joubert
*/

#include "../include/my.h"

char	**is_touched(char **map, t_vector C, char c)
{
  char  **dest;
  int   i;
  int   j;
  int   k;

  k = j = i = 0;
  dest = malloc(sizeof(char *) * 11);
  while (i != C.y)
    dest[j++] = strdup(map[i++]);
  dest[j] = malloc(sizeof(char) * 18);
  while (map[i][k])
    {
      if (k == C.x)
	{
	  if (map[i][k] == '.')
	    {
	      my_putstr("Wrong !\n", 1);
	      return (map);
	    }
	  dest[j][k++] = c;
	}
      dest[j][k] = map[i][k];
      k++;
    }
  dest[j][k] = 0;
  while (map[++i])
    dest[++j] = strdup(map[i]);
  dest[j + 1] = NULL;
  return (dest);
}

char	**my_position_init(char **map, t_vector C, char c)
{
  char	**dest;
  int	i;
  int	j;
  int	k;

  k = j = i = 0;
  dest = malloc(sizeof(char *) * 11);
  while (i != C.y)
    dest[j++] = strdup(map[i++]);
  dest[j] = malloc(sizeof(char) * 18);
  while (map[i][k])
    {
      if (k == C.x)
	dest[j][k++] = c;
      dest[j][k] = map[i][k];
      k++;
    }
  dest[j][k] = 0;
  while (map[++i])
    dest[++j] = strdup(map[i]);
  dest[j + 1] = NULL;
  return (dest);
}

char	**my_position(char *buff)
{
  char	**all_cases;
  char	**map;
  int	i;
  int	time;

  i = 0;
  time = -1;
  all_cases = ret_all_cases(buff);
  map = my_init_map();
  while (++time != 2)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 50);
  time = -1;
  while (++time != 3)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 51);
  time = -1;
  while (++time != 4)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 52);
  time = -1;
  while (++time != 5)
    map = my_position_init(map, convert_co_char(all_cases[i++]), 53);
  return (map);
}

t_vector	convert_co_char(char *number)
{
  t_vector	C;
  int	i;
  char  letter[] = " |A B C D E F G H";
  char  nb[] = " -12345678";

  i = -1;
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

  while (letter[i])
    if (x + 64 == letter[i++])
      {
	C.x = i - 1;
	break;
      }
  i = 0;
  while (nb[i])
    if (y == nb[i++] - 48)
      {
	C.y = i - 1;
	break;
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
      map[i] = strcat(map[i], ". . . . . . . .\n\0");
      i++;
    }
  map[i] = NULL;
  return (map);
}

char    **ret_all_cases(char *buff)
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
  return (H.all_case);
}
