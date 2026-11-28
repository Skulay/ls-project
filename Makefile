NAME    = ft_ls
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

LIBFT_DIR = libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRC = ls.c \
	file.c \
	opts.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c ls.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
