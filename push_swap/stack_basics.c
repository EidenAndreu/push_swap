/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:26:29 by ereinald          #+#    #+#             */
/*   Updated: 2023/08/28 21:22:05 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_create_stack(int capacity)
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    if (!stack->array)
        return (NULL);
    return (stack);
}

t_stack *ft_clone_stack(t_stack *stack)
{
    t_stack *clone;
    int i;

    i = 0;
    clone = create_stack(stack->capacity);
    while (i <= stack->top)
    {
        clone->array[i] = stack->array[i];
        i++;
    }
    clone->top = stack->top;
    return (clone);
}

int ft_stack_capacity(t_stack *stack)
{
    return (stack->top + 1);
}

int ft_top_element(t_stack *stack)
{
    return (stack->array[stack->top]);
}

void ft_print_stack(t_stack *stack)
{
    int i;

    i = 0;
    while (i <= stack->top)
    {
        printf("%d\n", stack->array[i]);
        i++;
    }
}