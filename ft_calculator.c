/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:53:57 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/03 20:57:26 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_calculate_cost(t_stack *stack)
{
    int size = stack->capacity;
    int position = stack->top;
    int target = stack->target;

    // Calcular costo para la posición actual y el objetivo
    int cost_position = position; // Costo por mover desde la posición actual
    int cost_target = abs(target - position); // Costo por mover al objetivo

    // Considerar caso en el que mover al objetivo por arriba o abajo
    if (target > position)
    {
        cost_target = size - cost_target; // Considerar movimiento en sentido contrario
    }

    // Actualizar los costos en la estructura
    stack->cost_position = cost_position;
    stack->cost_target = cost_target;
}

void ft_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_b;
	int cheapest_cost = INT_MAX;
	int best_cost_position = 0;
	int best_cost_target = 0;

	tmp_b = *stack_b;

	while (tmp_b)
	{
		int current_cost_position = abs(tmp_b->cost_position);
		int current_cost_target = abs(tmp_b->cost_target);
		int current_total_cost = current_cost_position + current_cost_target;

		if (current_total_cost < cheapest_cost)
		{
			cheapest_cost = current_total_cost;
			best_cost_position = tmp_b->cost_position;
			best_cost_target = tmp_b->cost_target;
		}

		tmp_b = tmp_b->next;
	}

	// Llamada a la función para realizar el movimiento más económico
	ft_move(stack_a, stack_b, best_cost_position, best_cost_target);
}
