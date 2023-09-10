/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:08:08 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/08 19:08:08 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_position(t_stack **stack)
{
	t_stack		*tmp;
	int			i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	ft_get_target(t_stack **stack_a, int index_b, int target_i, int target)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index > index_b && tmp->index < target_i)
		{
			target_i = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_i != INT_MAX)
		return (target);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index < target_i)
		{
			target_i = tmp->index;
			target = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (target);
}

int	ft_min_position_index(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_i;
	int		lowest_p;

	tmp = *stack;
	lowest_i = INT_MAX;
	ft_get_position(stack);
	lowest_p = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_i)
		{
			lowest_i = tmp->index;
			lowest_p = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_p);
}

void	ft_get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		target;

	tmp = *stack_b;
	ft_get_position(stack_a);
	ft_get_position(stack_b);
	target = 0;
	while (tmp)
	{
		target = ft_get_target(stack_a, tmp->index, INT_MAX, target);
		tmp->target = target;
		tmp = tmp->next;
	}
}
