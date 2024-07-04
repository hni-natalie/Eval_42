/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:31 by hheng             #+#    #+#             */
/*   Updated: 2024/07/03 09:05:32 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	while (current->next)
		current = current->next;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	current->next = temp;
}

void	ra(t_stack **stk_a)
{
	rotate(stk_a);
}

void	rb(t_stack **stk_b)
{
	rotate(stk_b);
}

void	rr(t_stack **stk_a, t_stack **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
}
