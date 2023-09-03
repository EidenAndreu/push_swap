/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:16:46 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/03 20:57:52 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct
{
    int *array;
    int capacity;
    int top;
    int cost_position;
    int cost_target;
    int target;
    struct t_stack *next;
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

void        ft_push(t_stack *stack, int item);
void        ft_push_a(t_stack *a, t_stack *b);
void        ft_push_b(t_stack *a, t_stack *b);

void        ft_swap(t_stack *stack);
void        ft_swap_a(t_stack *a);
void        ft_swap_b(t_stack *b);
void        ft_swap_ab(t_stack *a, t_stack *b);

void        ft_rotate(t_stack *stack);
void        ft_rotate_a(t_stack *a);
void        ft_rotate_b(t_stack *b);
void        ft_rotate_ab(t_stack *a, t_stack *b);

void        ft_reverse_rotate(t_stack *stack);
void        ft_reverse_rotate_a(t_stack *a);
void        ft_reverse_rotate_b(t_stack *b);
void        ft_reverse_rotate_ab(t_stack *a, t_stack *b);

void        ft_calculate_cost(t_stack *stack);
void        ft_cheapest_move(t_stack **stack_a, t_stack **stack_b);

static void ft_rotate_all(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
static void ft_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
static void ft_ra(t_stack **a, int *cost);
static void ft_rb(t_stack **b, int *cost);
void        ft_move(t_stack **a, t_stack **b, int cost_a, int cost_b);


#endif
