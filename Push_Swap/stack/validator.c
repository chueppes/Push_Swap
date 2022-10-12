/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:12 by acalvo4           #+#    #+#             */
/*   Updated: 2022/10/11 21:58:12 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] < '0') || (str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(int *array_a, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (array_a[i] == array_a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	validate_values(char *argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (!ft_isnum(argv))
			ft_puterror();
		i++;
	}
}

int	is_it_ordered(int argc, int *array)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (array[i] < array[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_my_stack_sorted(t_stack *stack)
{
	int	i;

	i = stack->index + 1;
	while (--i > 0)
		if (stack->aux_array[i] > stack->aux_array[i - 1])
			return (0);
	return (1);
}
