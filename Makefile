# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 20:16:42 by ereinald          #+#    #+#              #
#    Updated: 2023/08/31 20:43:09 by ereinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
INCLUDE = .
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE) -I$(LIBFT)
RM = rm -f
AR = ar rcs

SRC_FILES = push_swap.c stack_utils.c stack_basics.c swap.c push.c rotate.c reverse_rotate.c \\
			ft_move.c calculate.c

SRC = $(SRC_FILES)
OBJ = $(SRC:.c=.o)
HDR_FILES = push_swap.h libft/libft.h

all: $(NAME)

$(NAME): $(OBJ) $(HDR_FILES) Makefile
	@$(MAKE) -C $(LIBFT)
	@cp $(LIBFT)/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC) $(HDR_FILES) Makefile
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(MAKE) clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re