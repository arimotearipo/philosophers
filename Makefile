SRCS = main.c ft_atoi.c routine.c time.c death_thread.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = philo

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:	
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all