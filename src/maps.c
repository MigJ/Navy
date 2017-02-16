/*
** maps.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:42:57 2017 miguel joubert
** Last update Thu Feb 16 22:35:55 2017 Joubert Miguel
*/

#include "../include/my.h"

t_vector	convert_co_char(char *number)
{
  t_vector	C;
  int	i;
  char  letter[] = " |A B C D E F G H";
  char  nb[] = " -12345678";

  i = -1;
  if (number == NULL)
    {
      C.x = C.y = 0;
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
  char  letter[] = " |A B C D E F G H";
  char  nb[] = " -12345678";

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

void	my_disp_map(char **map, char *name)
{
  int	i;

  i = 0;
  if (strcmp(name, "my_map") == 0)
    my_putstr("\nmy positions:\n", 1);
  else
    my_putstr("\nenemy's positions:\n", 1);
  while (map[i])
    my_putstr(map[i++], 1);
}

char	**my_init_map()
{
  char	**map;
  int	i;

  i = 0;
  if ((map = malloc(sizeof(char *) * 11)) == NULL)
    return (NULL);
  while (i != 11)
    if ((map[i++] = malloc(sizeof(char) * 18)) == NULL)
      return (NULL);
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
  if ((H.all_case = malloc(sizeof(char *) * 15)) == NULL)
    return (NULL);
  while (H.i != 29)
    {
      if (buff[H.i] != buff[H.i + 3] && H.bol == 0) H = case_cpy(buff, H);
      else if (buff[H.i + 4] - buff[H.i + 1] != 1
	       && buff[H.i + 4] - buff[H.i + 1] != 0
	       && H.bol == 0) H = case_cpy_second(buff, H);
      H = case_cpy_third(buff, H);
    }
  if ((H.all_case[H.j] = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  *H.all_case[H.j] = buff[29];
  H.all_case[H.j][1] = buff[30];
  H.all_case[H.j++][2] = 0;
  H.all_case[H.j] = NULL;
  return (H.all_case);
}
