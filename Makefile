NAME = fractol

INCLUDES = -Iincludes
OBJS_DIR = objects
SRCS = main.c
OBJS = $(addprefix objects/, $(SRCS:.c=.o))

LIBFT_DIR = ./libft/
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

CC = cc
FLAGS = -Wall -Werror -Wextra 
FLAGS_MLX = -lmlx -lX11 -Imlx -lXext

objects/%.o: source/%.c includes/fractol.h
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $^ $(LIBFT) $(FLAGS_MLX) -o $@

all: libft $(NAME)

libft:
	@make -C ./libft

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean:clean
	make fclean -C ./libft
	rm -rf  $(NAME)

re: fclean all