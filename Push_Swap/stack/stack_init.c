/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:58:16 by acalvo4           #+#    #+#             */
/*   Updated: 2022/10/11 21:58:17 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*initialize_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->index = -1;
	stack->aux_array = (int *)ft_calloc(size, sizeof(int));
	return (stack);
}

static void	insert_item(t_stack *stack, int n)
{
	int	i;

	stack->index++;
	i = stack->index;
	while (i > 0)
	{
		stack->aux_array[i] = stack->aux_array[i - 1];
		i--;
	}
	stack->aux_array[0] = n;
}

int	*get_values(int *array, int argc, char **argv)
{
	int		i;
	long	check;

	i = 0;
	check = 0;
	array = malloc(sizeof(int) * argc);
	while (i < argc)
	{
		validate_values(argv[i], argc);
		check = ft_atoi_mod(argv[i]);
		if (check == 2147483648)
			ft_puterror();
		array[i] = ft_atoi_mod(argv[i]);
		i++;
	}
	if (is_it_ordered(argc, array) == 1)
		exit(EXIT_FAILURE);
	return (array);
}

int	build_stack(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;
	int	*array;
	int	*right_array;

	i = 0;
	j = 0;
	array = NULL;
	array = get_values(array, argc, argv);
	if (!check_duplicates(array, argc))
		return (ft_puterror());
	right_array = bubble_sort(argc, argv);
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (array[i] == right_array[j])
				insert_item(stack, j);
			j++;
		}
		i++;
	}
	free_array(array, right_array);
	return (1);
}

void	free_array(int *array, int *right_array)
{
	free(array);
	free(right_array);
}
