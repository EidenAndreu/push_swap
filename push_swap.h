/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:16:46 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/28 21:23:08 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
    int *array;
    int capacity;
    int top;
} t_stack;

t_stack     *ft_create_stack(int capacity);
t_stack     *ft_clone_stack(t_stack *stack);
int         ft_stack_capacity(t_stack *stack);
int         ft_top_element(t_stack *stack);
void        ft_print_stack(t_stack *stack);

int         ft_is_empty(t_stack *stack);
int         ft_is_full(t_stack *stack);
void        ft_free_stack(t_stack *stack);
int         ft_peek(t_stack *stack);
int         ft_pop(t_stack *stack);

#endif
