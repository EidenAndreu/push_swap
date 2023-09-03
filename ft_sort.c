/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:12:44 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/03 21:43:04 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

void	ft_sort_three(t_stack **stack)
{
	int	biggest;

	if (ft_is_sorted(*stack))
		return ;
	biggest = ft_max_index(*stack);
	if ((*stack)->index == biggest)
		ft_rotate_a(stack);
	else if ((*stack)->next->index == biggest)
		ft_reverse_rotate_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		ft_swap_a(stack);
}

static void	ft_push_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = ft_get_stack_size(*stack_a);
	pushes = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushes < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_push_b(stack_a, stack_b);
			pushes++;
		}
		else
			ft_rotate_a(stack_a);
		i++;
	}
	while (stack_size - pushes > 3)
	{
		ft_push_b(stack_a, stack_b);
		pushes++;
	}
}

static void	ft_sort_stack(t_stack **stack_a)
{
	int	min_position;
	int	stack_size;

	stack_size = ft_get_stack_size(*stack_a);
	min_position = ft_min_index_position(stack_a);
	if (min_position > stack_size / 2)
	{
		while (min_position < stack_size)
		{
			ft_reverse_rotate_a(stack_a);
			min_position++;
		}
	}
	else
	{
		while (min_position > 0)
		{
			ft_rotate_a(stack_a);
			min_position--;
		}
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_init(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		ft_calculate_cost(stack_a);
		ft_cheapest_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_sort_stack(stack_a);
}