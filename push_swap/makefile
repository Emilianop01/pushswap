NAME		=	push_swap

SRC			=	atoi.c checks.c checks2.c findeco.c frees.c mosse.c mosse2.c mosse3.c push_swap.c pushrotator.c rotations.c solve.c solvefinal.c stack.c\

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

re:			fclean all

git:
	git add .
	git commit -m "update"
	git push

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

.PHONY:		all clean fclean re