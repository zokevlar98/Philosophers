NAME = philo

CFLAGS = -Wall -Wextra -Werror -I ./includes

RM = rm -rf

SRCS = 		mandatory/philo.c		\
			mandatory/usage.c		\


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o:%.c includes/philo.h
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean