/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheong <rcheong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:45:10 by rcheong           #+#    #+#             */
/*   Updated: 2024/06/23 16:06:09 by rcheong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_node *stack, char *str)
{
	int	temp;
	int	temp2;

	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	temp2 = stack->s_index;
	stack->s_index = stack->next->s_index;
	stack->next->s_index = temp2;
	if (ft_strncmp(str, "sa", 2) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(str, "sb", 2) == 0)
		write(1, "sb\n", 3);
}

void	push(t_node **stack_1, t_node **stack_2, char *str)
{
	t_node	*temp;

	if (!stack_1 || !stack_2 || !(*stack_2))
		return ;
	temp = *stack_2;
	*stack_2 = (*stack_2)->next;
	temp->next = *stack_1;
	*stack_1 = temp;
	if (ft_strncmp(str, "pa", 2) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(str, "pb", 2) == 0)
		write(1, "pb\n", 3);
}

void	rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	while (cost)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		temp->next = NULL;
		lst_last((*stack))->next = temp;
		if (ft_strncmp(str, "ra", 2) == 0)
			write(1, "ra\n", 3);
		else if (ft_strncmp(str, "rb", 2) == 0)
			write(1, "rb\n", 3);
		cost--;
	}
}

void	rev_rotate(t_node **stack, char *str, int cost)
{
	t_node	*temp;
	t_node	*looping;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (cost < 0)
	{
		temp = lst_last(*stack);
		looping = *stack;
		while (looping->next != NULL && looping->next->data != temp->data)
			looping = looping->next;
		looping->next = NULL;
		temp->next = *stack;
		*stack = temp;
		if (ft_strncmp(str, "rra", 3) == 0)
			write(1, "rra\n", 4);
		else if (ft_strncmp(str, "rrb", 3) == 0)
			write(1, "rrb\n", 4);
		cost++;
	}
}
