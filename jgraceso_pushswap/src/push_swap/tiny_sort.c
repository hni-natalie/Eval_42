/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:07:49 by jgraceso          #+#    #+#             */
/*   Updated: 2024/09/22 15:07:50 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_index(t_stack *stack)
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

void	tiny_sort(t_stack **stack)
{
	int	highest;

	if (!is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
