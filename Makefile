# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 21:32:20 by ereinald          #+#    #+#              #
#    Updated: 2023/09/10 21:32:20 by ereinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap
INCLUDE = .
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE)
RM = rm -f

# Lista de archivos fuente
SRC_FILES = ft_push_swap.c ft_calculator.c ft_errors.c ft_libft.c ft_movements.c ft_position.c \
			ft_push.c ft_reverse_rotate.c ft_rotate.c ft_sort_three.c \
			ft_swap.c ft_utils.c ft_sort.c ft_stack_utils.c

# Lista de objetos a compilar
OBJ = $(SRC_FILES:.c=.o)

HDR_FILES = push_swap.h

all: $(NAME)

$(NAME): $(OBJ) $(HDR_FILES) Makefile
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re