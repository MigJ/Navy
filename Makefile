CC	=	gcc

BUG	=	gcc -g3

NAME	=	navy

SRC	=	src/*.c

LIB	=

CFLAGS	=	-W -Wall -Wextra -pedantic

RM	=	rm -fr

all	:	$(NAME)

$(NAME)	:

		$(CC) -o $(NAME) $(SRC) $(CFLAGS) -L lib -lmy -lgnl

debug :
		$(BUG) -o $(NAME) $(SRC) $(CFLAGS) -L lib -lmy -lgnl

clean	:

		$(RM) $(OBJ)

fclean	:	clean

		$(RM) $(NAME)

re	:	fclean all
