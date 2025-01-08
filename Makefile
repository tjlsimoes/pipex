NAME := pipex

LIBFT := libft/libft.a
PRINTF := printf/libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS = -g

SRC := main.c
# push_swap.c stack_a.c stack_b.c stack_init.c \
# sort_a.c sort_b.c \
# operations_a.c operations_b.c operations_c.c operations_d.c\
# best_nbr_moves.c calcs_ba.c calcs_ab.c\
# error.c ft_atoi_alt.c ft_split_size.c \
# split_clear.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
#	cd printf && $(MAKE)
#	cd libft && $(MAKE)
#	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
## $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
#	cd printf && $(MAKE) clean
#	cd libft && $(MAKE) clean
	$(RM) $(OBJ)

fclean: clean
#	cd printf && $(MAKE) fclean
#	cd libft && $(MAKE) fclean
	$(RM) $(NAME)

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(OBJ)
	cd printf && $(MAKE)
	cd libft && $(MAKE)
	$(CC) -g $(CFLAGS) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
