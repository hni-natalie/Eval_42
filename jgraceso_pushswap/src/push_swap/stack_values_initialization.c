/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_values_initialization.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:07:20 by jgraceso          #+#    #+#             */
/*   Updated: 2024/09/22 15:07:24 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (av[i])
	{
		nb = ft_atol(av[i]);
		if (i == 1)
		{
			stack_a = new_node((int)(nb));
			if (!stack_a)
				return (NULL);
		}
		else
			stack_add_bottom(&stack_a, new_node((int)(nb)));
		i++;
	}
	if (ac == 2)
		free_arr(av);
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int i)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (i-- > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = i;
	}
}
