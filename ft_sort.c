/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:43:25 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/08 16:18:13 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushes;
	int	i;

	stack_size = ft_stack_size(*stack_a);
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
	int	lowest_p;
	int	stack_size;

	stack_size = ft_stack_size(*stack_a);
	lowest_p = ft_min_position_index(stack_a);
	if (lowest_p > stack_size / 2)
	{
		while (lowest_p < stack_size)
		{
			ft_reverse_rotate_a(stack_a);
			lowest_p++;
		}
	}
	else
	{
		while (lowest_p > 0)
		{
			ft_rotate_a(stack_a);
			lowest_p--;
		}
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_init(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_get_target_position(stack_a, stack_b);
		ft_cost(stack_a, stack_b);
		ft_cheapest_move(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_sort_stack(stack_a);
}