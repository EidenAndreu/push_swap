/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:16:34 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/03 21:29:33 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(t_stack *stack)
{
    int i = 0;
    while (i < stack->top) {
        if (stack->array[i] > stack->array[i + 1]) {
            return 0; // No está ordenada
        }
        i++;
    }
    return 1; // Está ordenada
}

/*

https://github.dev/abeph00/Push_Swap
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    a = ft_create_stack(argc - 1);
    b = ft_create_stack(argc - 1);
    ft_parse_stack(a, argc, argv);
    if (ft_is_sorted(a))
        return (0);
    ft_sort(a, b);
    ft_free_stack(a);
    ft_free_stack(b);
    return (0);
}
*/