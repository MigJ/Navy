##
## Makefile for  in /home/miguel.joubert/delivery/PSU_2016_navy
## 
## Made by miguel joubert
## Login   <miguel.joubert@epitech.net>
## 
## Started on  Mon Jan 30 15:22:51 2017 miguel joubert
## Last update Tue Jan 31 02:07:01 2017 miguel joubert
##

PROJECT	=	src/main.c		\
		src/verify.c		\
		src/tools.c		\
		src/maps.c		\

FLAGS	=	-Wall -Werror -W -Wextra

NAME	=	navy

all:	$(NAME)

$(NAME):	$(PROJECT)
	$(CC) -g $(PROJECT) -o $(NAME) $(FLAGS) -lgnl

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean	all
