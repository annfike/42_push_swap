SRCS =  push_swap.c	list.c	ft_split.c		parse_argv.c	rotate.c	list1.c \
		sorting1.c	main.c	find_place_b.c	find_place_a.c	sorting2.c	list2.c
	
OBJS = ${SRCS:.c=.o}

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
			$(CC) $(CFLAGS)  -o $(NAME) $(OBJS)

clean:
			${RM} ${OBJS} 

fclean: clean
			${RM} ${NAME}

re: fclean all