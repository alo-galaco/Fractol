NAME = fractol

INCLUDES = -Iincludes
OBJS_DIR = objects
OBJS = $(addprefix objects/, $(SRCS:.c=.o))
SRCS =	main.c \
		fractol_mandelbrot.c \
		fractol_julia.c \
		check_arg.c \
		hooks.c

LIBFT_DIR = ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CC = cc
FLAGS = -Wall -Werror -Wextra 
FLAGS_MLX = -lmlx -lX11 -Imlx -lXext

all: libft $(NAME)

objects/%.o: source/%.c includes/fractol.h
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $^ $(LIBFT) $(FLAGS_MLX) -o $@

libft:
	@make -C ./libft

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean:clean
	make fclean -C ./libft
	rm -rf  $(NAME)

re: fclean all

.PHONY: all libft clean fclean re