/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:25:56 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/28 21:57:02 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push(t_stack *stack, int item)
{
    if (is_full(stack))
        return ;
    stack->array[++stack->top] = item;
}

void ft_push_a(t_stack *a, t_stack *b)
{
    if (is_empty(b))
        return ;
    ft_push(a, ft_pop(b));
    ft_putendl_fd("pa", 1);
}

void ft_push_b(t_stack *a, t_stack *b)
{
    if (is_empty(a))
        return ;
    ft_push(b, ft_pop(a));
    ft_putendl_fd("pb", 1);
}
