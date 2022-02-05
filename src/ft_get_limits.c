/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_limits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:29:59 by fbonini-          #+#    #+#             */
/*   Updated: 2021/12/04 16:25:32 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_find_position(t_stack *stack, int size, int a_pos)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	stack->max_numb = ft_get_max_numb(stack->stack_a, size, &index);
	if (stack->stack_b[a_pos] > stack->max_numb)
		return (index + 1);
	stack->min_numb = ft_get_min_numb(stack->stack_a, size, &index);
	if (stack->stack_b[a_pos] < stack->min_numb)
		return (index);
	while (i < size)
	{
		if (stack->stack_b[a_pos] > stack->stack_a[i]
			&& stack->stack_b[a_pos] < stack->stack_a[i + 1])
			return (++i);
		i++;
	}
	return (++i);
}

void	ft_initial_mids(t_stack *stack)
{
	if (stack->mid == 0)
		stack->mid = stack->size * 0.5;
	if (stack->counter == stack->size * 0.5)
	{
		stack->counter = 0;
		stack->mid = stack->mid + stack->size * 0.3;
	}
	else if (stack->counter == stack->size * 0.3
		&& stack->mid >= stack->size * 0.8)
	{
		stack->counter = 0;
		stack->mid = stack->mid + (stack->size * 0.1);
	}
	else if (stack->counter == (stack->size * 0.1)
		&& stack->mid >= stack->size * 0.9)
	{
		stack->counter = 0;
		stack->mid = stack->mid + (stack->size * 0.05);
	}
}

void	ft_mid_mids(t_stack *stack)
{
	if (stack->mid == 0)
		stack->mid = stack->size * 0.45;
	if (stack->counter == stack->size * 0.45)
	{
		stack->counter = 0;
		stack->mid = stack->mid + stack->size * 0.3;
	}
	else if (stack->counter == stack->size * 0.3
		&& stack->mid >= stack->size * 0.75)
	{
		stack->counter = 0;
		stack->mid = stack->mid + (stack->size * 0.1);
	}
	else if (stack->counter == (stack->size * 0.1)
		&& stack->mid >= stack->size * 0.85)
	{
		stack->counter = 0;
		stack->mid = stack->mid + (stack->size * 0.05);
	}
}

void	ft_last_mids(t_stack *stack)
{
	if (stack->mid == 0)
		stack->mid = stack->size * 0.25;
	if (stack->counter == stack->size * 0.25
		&& stack->mid <= stack->size * 0.55)
	{
		stack->counter = 0;
		stack->mid = stack->mid + stack->size * 0.3;
	}
	else if (stack->counter == stack->size * 0.3
		&& stack->mid >= stack->size * 0.85)
	{
		stack->counter = 0;
		stack->mid = stack->mid + stack->size * 0.25;
	}
	else if (stack->counter == stack->size * 0.25
		&& stack->mid >= stack->size * 0.85)
	{
		stack->counter = 0;
		stack->mid = stack->mid + stack->size * 0.15;
	}
}
