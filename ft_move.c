/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:40:12 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/03 20:57:25 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

static void	ft_rotate_all(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_reverse_rotate_ab(a, b);
	}
    while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rotate_ab(a, b);
	}
}

static void	ft_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rotate_ab(a, b);
	}
}

static void	ft_ra(t_stack **a, int *cost)
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

static void	ft_rb(t_stack **b, int *cost)
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
			ft_reverse_rotate_b(b);
			(*cost)++;
		}
	}
}

void	ft_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_reverse_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_both(a, b, &cost_a, &cost_b);
	ft_ra(a, &cost_a);
	ft_rb(b, &cost_b);
	ft_push_a(a, b);
}
