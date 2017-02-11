/*
** position.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 22:07:28 2017 miguel joubert
** Last update Sat Feb 11 17:58:36 2017 miguel joubert
*/

#include "../include/my.h"

int	verify_length(char *buff)
{
  int	i;
  int	j;
  char	*stock;

  if (buff[28] != ':') return (1);
  if (buff[0] < '2' || *buff > '5') return (1);
  stock = malloc(sizeof(char) * 6);
  j = i = 0;
  *stock = *buff;
  while (buff[i])
    if (buff[i++] == '\n')
      stock[++j] = buff[i];
  stock[++j] = 0;
  i = 0;
  j = 1;
  while (stock[i])
    {
      while (stock[j])
	if (stock[i] == stock[j++] || (stock[i] >= '5' && stock[i] <= '2'))
	  return (1);
      i++;
      j = i + 1;
    }
  return (0);
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
      if (k == C.x) dest[j][k++] = c;
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
