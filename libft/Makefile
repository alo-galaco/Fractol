# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcristi <flcristi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 02:14:58 by coder             #+#    #+#              #
#    Updated: 2023/04/29 12:29:29 by flcristi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strdup.c \
		ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_substr.c ft_strjoin.c \
		ft_striteri.c ft_putnbr_fd.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strcmp.c\

BONUS_SRCS =	ft_lstnew.c ft_lstadd_front.c \
				ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJ	= ${SRCS:.c=.o}

BONUS_OBJ	= ${BONUS_SRCS:.c=.o}

NAME	= libft.a

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)

bonus: $(BONUS_OBJ)

%.o: %.c
	cc $(FLAGS) -c $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -f ${OBJ} ${BONUS_OBJ}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re