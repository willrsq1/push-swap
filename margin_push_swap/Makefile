SRCS			=	main.c \
					algorithm.c \
					lst_utils.c \
					push_and_swap_functs.c \
					rotate_functs.c \
					utils_algorithm.c \

HEADER 		=	push_swap.h

OBJS			=	$(SRCS:.c=.o)

CC				=	@gcc
RM				=	@rm -f
CFLAGS			=	-Werror -Wextra -Wall

NAME			=	push_swap

all:			$(NAME)
				@mv *.o .objs/

$(NAME):		${OBJS}
				${CC} ${CFLAGS} $(HEADER) ${OBJS} -o ${NAME}

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re