/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:17:03 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/30 20:33:55 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_alloc_arrays(t_stack *stack, int size)
{
	stack->stack_a = (int *) malloc(sizeof(int) * size);
	if (!stack->stack_a)
		return (1);
	stack->stack_b = (int *) malloc(sizeof(int) * size);
	if (!stack->stack_b)
		return (1);
	stack->stack_c = (int *) malloc(sizeof(int) * size);
	if (!stack->stack_c)
		return (1);
	return (0);
}

void	ft_alloc_stack(t_stack *stack, int size)
{
	if (ft_alloc_arrays(stack, size))
	{
		ft_free_stack(stack);
		ft_error();
	}
	stack->size = size;
	stack->size_1 = 0;
	stack->size_2 = 0;
	stack->max_numb = 0;
	stack->min_numb = 0;
	stack->uper = 0;
	stack->mid = 0;
	stack->lower = 0;
	stack->counter = 0;
	stack->index = 0;
}
