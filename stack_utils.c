/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:31:50 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/28 21:23:07 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_empty(t_stack *stack)
{
    return (stack->top == -1);
}

int ft_is_full(t_stack *stack)
{
    return (stack->top == stack->capacity - 1);
}

void ft_free_stack(t_stack *stack)
{
    free(stack->array);
    free(stack);
}

int ft_peek(t_stack *stack)
{
    if (is_empty(stack))
        return (-1);
    return (stack->array[stack->top]);
}

int ft_pop(t_stack *stack)
{
    if (is_empty(stack))
        return (-1);
    return (stack->array[stack->top--]);
}