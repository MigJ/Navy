/*
** proto.h for navy in /home/nathan.trehout/delivery/PSU_2016_navy
** 
** Made by Nathan Trehout
** Login   <nathan.trehout@epitech.net>
** 
** Started on  Tue Jan 31 15:56:57 2017 Nathan Trehout
** Last update Wed Feb  1 22:22:21 2017 miguel joubert
*/

void    sig_handler(int sig);

void HandleSignal(int sig, siginfo_t *si, void *context);

int     get_pidclient();

unsigned int     receive_bit(pid_t pid_client);

int     server_init();

void    send_bit(unsigned int    nb, int pid_server);

int     client_init(int pid_server);

int	my_getnbr(char *str);

int	my_printf(char *str, ...);

