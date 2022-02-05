/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:33:53 by fbonini-          #+#    #+#             */
/*   Updated: 2021/12/05 15:00:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_stack_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->size - i != 3)
	{
		ft_pull_to_stack(stack->stack_a, stack->stack_b, stack->size - i, i);
		write(1, "pb\n", 3);
		i++;
	}
	ft_three_sort(stack->stack_a);
	while (i > 0)
	{
		stack->index = ft_find_position(stack, stack->size - i - 1, 0);
		if (stack->index <= (stack->size - i) / 2)
			ft_rotate_stack_a(stack, 'u', stack->size - i);
		else
			ft_rotate_stack_a(stack, 'd', stack->size - i);
		ft_pull_to_stack(stack->stack_b, stack->stack_a, i,
			stack->size - i - 1);
		write(1, "pa\n", 3);
		i--;
	}
	ft_final_rotation(stack);
}
