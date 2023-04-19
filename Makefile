NAME = fractol

INCLUDES = -Iincludes
OBJS_DIR = objects
SRCS = main.c
OBJS = $(addprefix objects/, $(SRCS:.c=.o))
FLAGS = -Wall -Werror -Wextra 

CC = cc
MLX = -lmlx -lX11 -Imlx -lXext

objects/%.o: source/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDES) $^ $(MLX) -o $@

all:$(NAME)

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean:clean
	make fclean -C ./libft
	rm -rf  $(NAME)

re: fclean all