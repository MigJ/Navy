/*
** my.h for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Mon Jan 30 15:28:37 2017 miguel joubert
** Last update Tue Feb 14 18:05:22 2017 miguel joubert
*/

# ifndef _NAVY_H
# define _NAVY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "struct.h"

char	**double_case(char **all_cases);

void     my_put_nbr(int nb);

int	verify_length(char *buff);

t_elem  init_buff(t_elem E, int ac, char **av);

void    sig_handler(int sig);

void HandleSignal(int sig, siginfo_t *si, void *context);

int     get_pidclient();

unsigned int     receive_bit(pid_t pid_client);

int     server_init();

void    send_bit(unsigned int    nb, int pid_server);

int     client_init(int pid_server);

int     my_getnbr(char *str);

int     my_printf(char *str, ...);

int	is_played(char **all_cases);

t_hit   init_case(t_hit H);

t_elem  init_elem(t_elem E, int ac, char **av);

t_map    init_map(t_map M, t_elem E);

int     help();

int    host(t_elem E, t_map M);

t_map   map_aftchd(t_map M, t_elem E, char *str, int cond);

int     client(t_elem E, t_map M);

int     verify_exist(char *buff);

char	**is_touched(char **map, t_vector C);

char    **my_position_init(char **map, t_vector C, char c);

char	*get_next_line(const int fd);

size_t  my_strlen(char *str);

void    my_putstr(char *str, int output);

int    verify_pos(char *buff);

t_hit   case_cpy(char *buff, t_hit H);

t_hit   case_cpy_second(char *buff, t_hit H);

t_hit   case_cpy_third(char *buff, t_hit H);

int    verify_hit(char *buff);

size_t  my_strlen(char *str);

void    my_putstr(char *str, int output);

char    **ret_all_cases(char *buff);

t_vector        convert_co_int(int x, int y);

void	my_disp_map(char **map, char *name);

t_vector        convert_co_char(char *number);

char    **my_position(char *buff);

char    **my_init_map();

char    *my_strcat(char *dest, char *src);

char	*pars_case(char *buff);

char    *pars_map(char *buff);

int	disp_all_map(char **my_map, char **map_adv);

# endif /* _NAVY_H */
