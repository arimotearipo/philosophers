SRCS = main.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = philo

all:		$(LIBFT) $(NAME)

$(NAME):	$(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:	
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all