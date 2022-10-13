/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:57:55 by acalvo4           #+#    #+#             */
/*   Updated: 2022/10/11 22:23:03 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 2 && ft_isalpha(argv[1][0]))
		ft_puterror();
	if (argc == 2)
		exit(EXIT_SUCCESS);
	stack_a = initialize_stack(argc - 1);
	stack_b = initialize_stack(argc - 1);
	build_stack(argc - 1, argv + 1, stack_a);
	sort(stack_a, stack_b);
	free(stack_a->aux_array);
	free(stack_b->aux_array);
	free(stack_a);
	free(stack_b);
	exit(EXIT_SUCCESS);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		return (sa(stack_a));
	if (stack_a->size == 3)
		return (small_sort(stack_a));
	if (stack_a->size <= 5 && stack_a->size > 3)
		return (medium_sort(stack_a, stack_b));
	else
		return (big_sort(stack_a, stack_b));
}

void	test(int argc, t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("[");
	while (i < argc - 1)
	{
		ft_printf("%i", stack->aux_array[i]);
		if (i < argc - 2)
			ft_printf(", ");
		i++;
	}
	ft_printf("] | index = %d", stack->index);
	ft_printf(" | topo = %d\n", stack->aux_array[stack->index]);
}
