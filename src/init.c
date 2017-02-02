/*
** init.c for  in /home/miguel.joubert/delivery/PSU_2016_navy
** 
** Made by miguel joubert
** Login   <miguel.joubert@epitech.net>
** 
** Started on  Wed Feb  1 19:49:12 2017 miguel joubert
** Last update Thu Feb  2 13:31:24 2017 Joubert Miguel
*/

#include "include/my.h"
#include "include/libs.h"
#include "include/proto.h"

int	client_init(int pid_server)
{
  int   pid;


  pid = getpid();
  signal(SIGUSR1, sig_handler);
  signal(SIGUSR2, sig_handler);
  my_printf("Pid : %d\n", pid);
  kill(pid_server, SIGUSR1);
  my_printf("successfully connected\n");
  sleep(2);
  send_bit(44, pid_server);
  return (pid_server);
}

int	server_init()
{
  pid_t pid_client;
  pid_t pid_server;

  pid_server = getpid();
  my_printf("my_pid: %d\n", pid_server);
  my_printf("waiting for enemy connexion...\n");
  pid_client = get_pidclient();
  my_printf("enemy connected\n");
  signal(SIGUSR1, sig_handler);
  signal(SIGUSR2, sig_handler);
  if (receive_bit(pid_client) != 44)
    exit (84);
  return (pid_client);
}

t_elem	init_elem(int ac, char **av, t_elem E)
{
  E.pid = (ac == 2) ? server_init() : client_init(my_getnbr(av[1]));
  E.i = (ac == 2) ? 1 : 2;
  if (E.i == 1) E.fd = open(av[1], O_RDONLY);
  else E.fd = open(av[2], O_RDONLY);
  E.buff = malloc(sizeof(char) * 33);
  read(E.fd, E.buff, 32);
  E.buff[31] = 0;
  E.win = 14;
  return (E);
}

t_map	init_map(t_map M, t_elem E)
{
  M.map_adv = my_init_map();
  printf("enemy's positions:\n");
  my_disp_map(M.map_adv);
  M.my_map = my_position(E.buff);
  printf("my positions:\n");
  my_disp_map(M.my_map);
  return (M);
}
