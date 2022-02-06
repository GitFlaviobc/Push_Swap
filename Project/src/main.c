/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:54:29 by fbonini-          #+#    #+#             */
/*   Updated: 2021/12/04 14:53:25 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_fill_stacks(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	fill_stack;

	i = 1;
	while (i <= argc)
	{
		fill_stack = ft_atoi(argv[i]);
		stack->stack_a[i - 1] = fill_stack;
		stack->stack_c[i - 1] = fill_stack;
		stack->stack_b[i - 1] = 0;
		i++;
	}
}

int	ft_not_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			break ;
		i++;
	}
	return (i);
}

void	ft_pick_sort(t_stack *stack)
{
	if (stack->size == 2)
		ft_two_sort(stack->stack_a);
	else if (stack->size == 3)
		ft_three_sort(stack->stack_a);
	else if (stack->size < 60)
		ft_stack_sort(stack);
	else if (stack->size >= 60)
		ft_big_sort(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	ft_check_args(argc - 1, argv);
	ft_alloc_stack(&stack, argc - 1);
	ft_fill_stacks(argc - 1, argv, &stack);
	ft_timsort(&stack);
	if (ft_not_sorted(stack.stack_a, stack.size) == stack.size - 1)
	{
		ft_free_stack(&stack);
		exit(0);
	}
	ft_pick_sort(&stack);
	ft_free_stack(&stack);
}
