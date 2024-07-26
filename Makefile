NAME = push_swap

SRC = push_swap.c utils_.c

OBJ = $(SRC:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

LIBFTPRINTF = ./ft_printf/libftprintf.a
LIBFTPRINTF_DIR = ./ft_printf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBFTPRINTF) -o $(NAME)

%.o: %.c $(LIBFTPRINTF) $(LIBFT)
		$(CC) $(CFLAGS) -I$(LIBFTPRINTF_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(LIBFTPRINTF):
		make -C $(LIBFTPRINTF_DIR)

$(LIBFT):
		make -C $(LIBFT_DIR)

clean:
		rm -f $(OBJ)
		make -C $(LIBFTPRINTF_DIR) clean
		make -C $(LIBFT_DIR) clean

fclean:
		rm -f $(NAME)
		make -C $(LIBFTPRINTF_DIR) fclean
		make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re