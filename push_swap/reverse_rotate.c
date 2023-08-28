/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:59:42 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/28 22:20:54 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(t_stack *stack)
{
    int tmp;
    int i;

    if (stack->top < 1)
        return ;
    tmp = stack->array[0];
    i = 0;
    while (i < stack->top)
    {
        stack->array[i] = stack->array[i + 1];
        i++;
    }
    stack->array[stack->top] = tmp;
}

void ft_reverse_rotate_a(t_stack *a)
{
    ft_reverse_rotate(a);
    ft_putendl_fd("rra", 1);
}

void ft_reverse_rotate_b(t_stack *b)
{
    ft_reverse_rotate(b);
    ft_putendl_fd("rrb", 1);
}

void ft_reverse_rotate_ab(t_stack *a, t_stack *b)
{
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
    ft_putendl_fd("rrr", 1);
}