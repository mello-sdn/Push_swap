NAME = libftprintf.a

SRCS = \
	ft_printf.c \
	ft_base.c \
	ft_char.c \
	ft_hexa.c \
	ft_int.c \
	utils.c \

OBJS = ${SRCS:.c=.o}

CC	= gcc
RM	= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}


$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re