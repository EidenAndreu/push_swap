/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:57:35 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/28 22:07:55 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack *stack)
{
    int tmp;

    if (stack->top < 1)
        return ;
    tmp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = tmp;
}

void ft_swap_a(t_stack *a)
{
    ft_swap(a);
    ft_putendl_fd("sa", 1);
}

void ft_swap_b(t_stack *b)
{
    ft_swap(b);
    ft_putendl_fd("sb", 1);
}

void ft_swap_ab(t_stack *a, t_stack *b)
{
    ft_swap(a);
    ft_swap(b);
    ft_putendl_fd("ss", 1);
}
