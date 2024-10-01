/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraceso <jgraceso@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:06:53 by jgraceso          #+#    #+#             */
/*   Updated: 2024/09/22 15:06:55 by jgraceso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

static int	get_target_largest(t_stack **a, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	target_pos = 0;
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

int	get_lowest_index_pos(t_stack **stack)
{
	int		pos;
	int		lowest_index;
	t_stack	*tmp;

	pos = 0;
	lowest_index = INT_MAX;
	set_pos(stack);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos);
}

static int	get_target(t_stack **a, int b_idx)
{
	int		target_idx;
	int		target_pos;
	t_stack	*tmp_a;

	target_idx = INT_MAX;
	target_pos = 0;
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	target_pos = get_target_largest(a, target_idx, target_pos);
	return (target_pos);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	set_pos(a);
	set_pos(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
