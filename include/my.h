/*
** my.h for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 15:28:37 2017 miguel joubert
** Last update Tue Jan 31 02:17:50 2017 miguel joubert
*/

#ifndef _NAVY_H
#define _NAVY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

char	**is_touched(char **map, t_vector C, char c);

char    **my_position_init(char **map, t_vector C, char c);

char	*get_next_line(const int fd);

size_t  my_strlen(char *str);

void    my_putstr(char *str, int output);

void    verify_pos(char *buff);

t_hit   case_cpy(char *buff, t_hit H);

t_hit   case_cpy_second(char *buff, t_hit H);

t_hit   case_cpy_third(char *buff, t_hit H);

void    verify_hit(char *buff);

size_t  my_strlen(char *str);

void    my_putstr(char *str, int output);

char    **ret_all_cases(char *buff);

t_vector        convert_co_int(int x, int y);

void	my_disp_map(char **map);

t_vector        convert_co_char(char *number);

char    **my_position(char *buff);

char    **my_init_map();

#endif /* _NAVY_H */
