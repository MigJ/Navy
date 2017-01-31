/*
** tools.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 23:39:04 2017 miguel joubert
** Last update Mon Jan 30 23:40:48 2017 miguel joubert
*/

#include "../include/my.h"

void    my_putstr(char *str, int output)
{
  int   i;

  i = 0;
  while (str[i])
    {
      write(output, &str[i], 1);
      i++;
    }
}

size_t  my_strlen(char *str)
{
  size_t        i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
