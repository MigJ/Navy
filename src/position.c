/*
** position.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 22:07:28 2017 miguel joubert
** Last update Wed Feb  1 22:12:15 2017 miguel joubert
*/

#include "../include/my.h"

char    **is_touched(char **map, t_vector C)
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
	      return (NULL);
	    }
	  dest[j][k++] = 'x';
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

char    **my_position_init(char **map, t_vector C, char c)
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

char    **my_position(char *buff)
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
