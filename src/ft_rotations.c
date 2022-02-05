/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:31:41 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/30 17:34:21 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pick_rotation(t_stack *stack, int i)
{
	if (stack->index <= i / 2)
		ft_rotate_stack_a(stack, 'u', i);
	else if (stack->index > i / 2)
		ft_rotate_stack_a(stack, 'd', i);
}

void	ft_rotate_stack_a(t_stack *stack, char rotation, int i)
{
	if (rotation == 'u')
	{
		while (stack->index > 0)
		{
			ft_rotate_up(stack->stack_a, i);
			write(1, "ra\n", 3);
			stack->index--;
		}
	}
	else if (rotation == 'd')
	{
		while (stack->index < i)
		{
			ft_rotate_down(stack->stack_a, i);
			write(1, "rra\n", 4);
			stack->index++;
		}
	}
}

void	ft_rotate_stack_b(t_stack *stack, char rotation, int i)
{
	if (rotation == 'u')
	{
		while (stack->uper > 0)
		{
			ft_rotate_up(stack->stack_b, stack->size - i);
			write(1, "rb\n", 3);
			stack->uper--;
		}
	}
	else if (rotation == 'l')
	{
		while (stack->lower >= 0)
		{
			ft_rotate_down(stack->stack_b, stack->size - i);
			write(1, "rrb\n", 4);
			stack->lower--;
		}
	}
}

void	ft_final_rotation(t_stack *stack)
{
	stack->max_numb = ft_get_min_numb(stack->stack_a, stack->size - 1, NULL);
	stack->min_numb = ft_get_min_numb(stack->stack_a, stack->size - 1, NULL);
	stack->uper = 0;
	stack->lower = 0;
	while (stack->stack_a[stack->uper] != stack->max_numb)
		stack->uper++;
	while (stack->stack_a[stack->size - stack->lower - 1] != stack->min_numb
		&& stack->lower <= stack->size)
		stack->lower++;
	if (stack->uper <= stack->lower)
	{
		stack->index = stack->uper;
		ft_rotate_stack_a(stack, 'u', stack->size);
	}
	else
	{
		stack->index = stack->size - stack->lower - 1;
		ft_rotate_stack_a(stack, 'd', stack->size);
	}
}
