/*
** tools.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:39:04 2017 miguel joubert
** Last update Sun Feb 19 21:03:53 2017 Joubert Miguel
*/

#include "../include/my.h"

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
  if ((dest = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
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

size_t	my_strlen(char *str)
{
  size_t        i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    i++;
  return (s1[i] - s2[i]);
}
