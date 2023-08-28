/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:58:46 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/28 21:59:27 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_stack *stack)
{
    int tmp;
    int i;

    if (stack->top < 1)
        return ;
    tmp = stack->array[stack->top];
    i = stack->top;
    while (i > 0)
    {
        stack->array[i] = stack->array[i - 1];
        i--;
    }
    stack->array[0] = tmp;
}

void ft_rotate_a(t_stack *a)
{
    ft_rotate(a);
    ft_putendl_fd("ra", 1);
}

void ft_rotate_b(t_stack *b)
{
    ft_rotate(b);
    ft_putendl_fd("rb", 1);
}

void ft_rotate_ab(t_stack *a, t_stack *b)
{
    ft_rotate(a);
    ft_rotate(b);
    ft_putendl_fd("rr", 1);
}
