/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:06:45 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/08 19:06:45 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_all(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_reverse_rotate_both(a, b);
	}
}

static void	ft_rotate_all(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_reverse_rotate(a, b);
	}
}

static void	rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rotate_a(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_reverse_rotate_a(a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rotate_b(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rerverse_rotate_b(b);
			(*cost)++;
		}
	}
}

void	ft_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_reverse_all(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_all(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	ft_push_a(a, b);
}
