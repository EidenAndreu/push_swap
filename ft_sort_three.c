/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:43:16 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/08 19:09:12 by ereinald         ###   ########.fr       */
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
