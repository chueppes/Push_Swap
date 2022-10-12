/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:22 by acalvo4           #+#    #+#             */
/*   Updated: 2022/10/11 21:58:22 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_sort(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	bottom;

	top = stack_a->aux_array[stack_a->index];
	middle = stack_a->aux_array[stack_a->index - 1];
	bottom = stack_a->aux_array[stack_a->index - 2];
	if (top > middle && bottom > middle && top < bottom)
		sa(stack_a);
	if (top > middle && middle > bottom && top > bottom)
	{
		sa(stack_a);
		rra(stack_a);
	}
	if (top > middle && bottom > middle && top > bottom)
		ra(stack_a);
	if (top < middle && middle > bottom && top < bottom)
	{
		sa(stack_a);
		ra(stack_a);
	}
	if (top < middle && middle > bottom && top > bottom)
		rra(stack_a);
}

void	medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	len;

	i = 0;
	len = stack_a->index;
	while (i <= len && stack_b->index < 1)
	{
		if (stack_a->aux_array[stack_a->index] == 0
			|| stack_a->aux_array[stack_a->index] == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	small_sort(stack_a);
	if (is_my_stack_sorted(stack_b))
		sb(stack_b);
	while (stack_b->index > -1)
		pa(stack_a, stack_b);
}

void	big_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	bits;
	int	i;

	bits = 0;
	i = 0;
	size = stack_a->index;
	while (!is_my_stack_sorted(stack_a))
	{
		i = 0;
		while (i <= size)
		{
			if (((stack_a->aux_array[stack_a->index] >> bits) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			i++;
		}
		while (stack_b->index >= 0)
			pa(stack_a, stack_b);
		bits++;
	}
}
