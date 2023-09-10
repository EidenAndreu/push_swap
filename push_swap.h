/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ereinald <ereinald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 20:42:34 by ereinald          #+#    #+#             */
/*   Updated: 2023/09/08 16:36:06 by ereinald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

long		ft_is_input_ok(char *av);
void		error_exit(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_get_index(t_stack *stack_a, int stack_size);
t_stack		*ft_new_stack(int value);
void		ft_add_stack(t_stack **stack, t_stack *new);
t_stack		*ft_get_bottom(t_stack *stack);
int			ft_stack_size(t_stack	*stack);
int			ft_is_sorted(t_stack *stack);
void		ft_sort_three(t_stack **stack);
void		ft_swap_a(t_stack **stack_a);
void		ft_swap_a(t_stack **stack_b);
void		ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void		ft_putstr(char *str);
void		ft_rotate_a(t_stack **stack_a);
void		ft_rotate_b(t_stack **stack_b);
void		ft_reverse_rotate(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_before_bottom(t_stack *stack);
void		ft_reverse_rotate_a(t_stack **stack_a);
void		ft_rerverse_rotate_b(t_stack **stack_b);
void		ft_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);
void		ft_push_a(t_stack **stack_a, t_stack **stack_b);
void		ft_push_b(t_stack **stack_a, t_stack **stack_b);
void		ft_sort(t_stack **stack_a, t_stack **stack_b);
void		ft_get_target_position(t_stack **stack_a, t_stack **stack_b);
void		ft_cheapest_move(t_stack **stack_a, t_stack **stack_b);
int			abs(int nb);
void		ft_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
int			ft_min_position_index(t_stack **stack);
char		**ft_split(char const *s, char c);
void		get_numbers(char *av, t_stack **stack_a);
int			ft_duplicate(t_stack *column);
size_t		ft_strlen(const char *s);
void		ft_cost(t_stack **stack_a, t_stack **stack_b);

#endif
