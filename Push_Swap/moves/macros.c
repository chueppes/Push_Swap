/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:32 by acalvo4           #+#    #+#             */
/*   Updated: 2022/10/11 21:58:32 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	int	aux;

	aux = 0;
	if (stack->index > 0)
	{
		aux = stack->aux_array[stack->index];
		stack->aux_array[stack->index] = stack->aux_array[stack->index - 1];
		stack->aux_array[stack->index - 1] = aux;
	}
}

void	rotate(t_stack *stack)
{
	int	i;
	int	aux;

	i = stack->index;
	aux = stack->aux_array[stack->index];
	while (i > 0)
	{
		stack->aux_array[i] = stack->aux_array[i - 1];
		i--;
	}
	stack->aux_array[0] = aux;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	aux;
	int	len;

	i = 0;
	len = stack->index;
	aux = stack->aux_array[0];
	while (i < len)
	{
		stack->aux_array[i] = stack->aux_array[i + 1];
		i++;
	}
	stack->aux_array[stack->index] = aux;
}

void	push(t_stack *take, t_stack *put)
{
	int	tmp;

	tmp = 0;
	tmp = take->aux_array[take->index];
	put->aux_array[++put->index] = tmp;
	take->aux_array[take->index--] = 0;
}
