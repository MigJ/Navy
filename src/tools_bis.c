/*
** tools_bis.c for  in /home/joubert/delivery/PSU_2016_navy
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Feb 19 20:50:46 2017 Joubert Miguel
** Last update Sun Feb 19 21:03:28 2017 Joubert Miguel
*/

#include "../include/my.h"

char	*my_strdup(char* str)
{
  int   len;
  char  *dup;

  len = my_strlen(str) + 1;
  dup = malloc(len);
  if (dup == NULL)
    return (NULL);
  dup = my_strcpy(dup, str);
  dup[len - 1] = 0;
  return (dup);
}

char	*my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
