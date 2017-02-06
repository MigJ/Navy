/*
** position.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 22:07:28 2017 miguel joubert
** Last update Mon Feb  6 15:42:33 2017 miguel joubert
*/

#include "../include/my.h"

char	*pars_map_line(char *buff)
{
  char	*dest;
  char	**tmp;
  int	tmp_i;
  int	i;
  int	j;
  int	k;

  i = j = k = 0;
  dest = malloc(sizeof(char) * 32);
  tmp = malloc(sizeof(char *) * 10);
  while (i != 32)
    {
      tmp_i = i;
      tmp[buff[tmp_i] - 48] = malloc(sizeof(char) * 10);
      while (i != tmp_i + 7)
	tmp[buff[tmp_i] - 48][j++] = buff[i++];
      i++;
      tmp[buff[tmp_i] - 48][j] = '\n';
      tmp[buff[tmp_i] - 48][++j] = 0;
      j = 0;
    }
  tmp[5][7] = 0;
  tmp[6] = NULL;
  j = 2;
  i = 0;
  while (tmp[j])
    {
      while (tmp[j][k])
	dest[i++] = tmp[j][k++];
      j++;
      k = 0;
    }
  dest[i] = 0;
  return (dest);
}

char    *pars_map_lowcase(char *buff)
{
  char  *dest;
  int   i;

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

char    *pars_map_order(char *buff)
{
  char  *dest;
  char  tmp;
  int   i;

  i = 2;
  dest = malloc(sizeof(char) * 32);
  dest = pars_map_lowcase(buff);
  while (i < 27)
    {
      if ((dest[i] >= '1' && dest[i] <= '8')
	  && (dest[i + 1] >= 'A' && dest[i + 1] <= 'Z'))
	{
	  tmp = dest[i];
	  dest[i] = dest[i + 1];
	  dest[i + 1] = tmp;
	}
      if ((dest[i + 3] >= '1' && dest[i + 3] <= '8')
	  && (dest[i + 4] >= 'A' && dest[i + 4] <= 'Z'))
	{
	  tmp = dest[i + 3];
	  dest[i + 3] = dest[i + 4];
	  dest[i + 4] = tmp;
	}
      i += 8;
    }
  return (dest);
}

char	*pars_map(char *buff)
{
  char	*dest;
  char	tmp;
  int	i;

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

char	**is_touched(char **map, t_vector C)
{
  t_touch	T;

  T.k = T.j = T.i = 0;
  T.dest = malloc(sizeof(char *) * 15);
  while (T.i != C.y)
    T.dest[T.j++] = strdup(map[T.i++]);
  T.dest[T.j] = malloc(sizeof(char) * 22);
  while (map[T.i][T.k])
    {
      if (T.k == C.x)
	{
	  if (map[T.i][T.k] == '.')
	    return (NULL);
	  T.dest[T.j][T.k++] = 'x';
	}
      T.dest[T.j][T.k] = map[T.i][T.k], T.k++;
    }
  T.dest[T.j][T.k] = 0;
  while (map[++T.i])
    T.dest[++T.j] = strdup(map[T.i]);
  T.dest[T.j + 1] = NULL;
  return (T.dest);
}

char	**my_position_init(char **map, t_vector C, char c)
{
  char  **dest;
  int   i;
  int   j;
  int   k;

  k = j = i = 0;
  dest = malloc(sizeof(char *) * 20);
  while (i != C.y)
    {
      dest[j] = strdup(map[i]);
      j++, i++;
    }
  dest[j] = malloc(sizeof(char) * 22);
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
  *dest[0] = ' ';
  return (dest);
}

char	**my_position(char *buff)
{
  char  **all_cases;
  char  **map;
  int   i;
  int   time;

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
