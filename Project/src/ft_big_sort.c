/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 09:44:53 by fbonini-          #+#    #+#             */
/*   Updated: 2021/12/04 15:24:39 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rotate_and_pull(t_stack *stack, int i)
{
	if (i > 2)
	{
		stack->index = ft_find_position(stack, i - 1, 0);
		ft_pick_rotation(stack, i);
		if (i < stack->size - 1)
			ft_pull_to_stack(stack->stack_b, stack->stack_a, stack->size, i);
		else
		{
			ft_pull_to_stack(stack->stack_b, stack->stack_a,
				stack->size - i - 1, i - 1);
		}
		write(1, "pa\n", 3);
	}
	else
	{
		ft_pull_to_stack(stack->stack_b, stack->stack_a, stack->size, i);
		write(1, "pa\n", 3);
		if (i == 2)
			ft_three_sort(stack->stack_a);
	}
}

void	ft_final_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->uper = 0;
		stack->lower = 0;
		ft_rotate_and_pull(stack, i);
		i++;
	}
	ft_final_rotation(stack);
}

void	ft_sort_parts(t_stack *stack, char tag, int i)
{
	if (i == 1)
		ft_sort_part1(stack, tag, i);
	else if (i == 2)
		ft_sort_part2(stack, tag, i);
	else if (i == 3)
		ft_sort_part3(stack, tag, i);
}

void	ft_big_sort(t_stack *stack)
{
	int		i;
	char	tag;

	i = 1;
	tag = 'a';
	while (i < 4)
	{
		stack->counter = 0;
		stack->mid = 0;
		ft_sort_parts(stack, tag, i);
		if (tag == 'a')
			tag = 'b';
		else if (tag == 'b')
			tag = 'a';
		i++;
	}
	ft_final_sort(stack);
}
