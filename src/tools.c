/*
** tools.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:39:04 2017 miguel joubert
** Last update Mon Feb  6 00:20:12 2017 miguel joubert
*/

#include "include/my.h"

int	help()
{
  my_putstr("USAGE\n", 1);
  my_putstr("           ./navy [first_player_pid] navy_positions\n", 1);
  my_putstr("DESCRIPTION\n", 1);
  my_putstr("           first_player_pid   only for the 2nd player.  pid of \
the first player.\n           navy_positions     file representing the positi\
ons of the ships.\n", 1);
  return (0);
}

char	*pars_case(char *buff)
{
  char	*dest;
  int	bol;

  bol = 0;
  dest = malloc(sizeof(char) * 3);
  if (buff == NULL)
    return (NULL);
  if (*buff == 0)
    return (NULL);
  if (*buff >= 'a' && *buff <= 'z')
    {
      *dest = *buff - 32;
      dest[1] = buff[1], bol = 1;
    }
  if (buff[1] >= 'a' && buff[1] <= 'z')
    {
      *dest = buff[1] - 32;
      dest[1] = *buff, bol = 1;
    }
  if (buff[1] >= 'A' && buff[1] <= 'Z') *dest = buff[1], bol = 1;
  if (*buff > '0' && *buff < '9') dest[1] = *buff, bol = 1;
  dest[2] = 0;
  return ((bol == 0) ? buff : dest);
}

char	*my_strcat(char *dest, char *src)
{
  char	*res;
  int	i;
  int	j;
  int	write;

  j = i = 0;
  if (dest == NULL)
    return (src);
  if (src == NULL)
    return (dest);
  while (dest[i])
    i++;
  while (src[j])
    j++;
  if ((res = malloc(sizeof(char) * ((i + j + 1) * 10))) == NULL)
    return (NULL);
  i = -1;
  write = 0;
  while (dest[++i])
    res[write++] = dest[i];
  i = -1;
  while (src[++i])
    res[write++] = src[i];
  res[write] = 0;
  return (res);
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

size_t	my_strlen(char *str)
{
  size_t        i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
