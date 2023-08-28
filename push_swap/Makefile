# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 20:16:42 by ereinald          #+#    #+#              #
#    Updated: 2023/08/28 20:21:36 by ereinald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
INCLUDE = .
LIBFT = libft
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE) -I$(LIBFT)
RM = rm -f
AR = ar rcs

SRC_FILES = ft_push_swap.c ft_utils.c ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c

SRC = $(SRC_FILES)
OBJ = $(SRC:.c=.o)
HDR_FILES = ft_push_swap.h libft/libft.h

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