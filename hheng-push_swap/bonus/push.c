/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng < hheng@student.42kl.edu.my>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:13:38 by hheng             #+#    #+#             */
/*   Updated: 2024/07/03 09:05:11 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp_src;

	if ((*src) == NULL)
		return ;
	temp_src = (*src)->next;
	(*src)->next = (*dest);
	*dest = *src;
	*src = temp_src;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}
