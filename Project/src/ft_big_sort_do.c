/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_do.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:22:37 by fbonini           #+#    #+#             */
/*   Updated: 2021/12/05 10:54:09 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_do_sort_part1(t_stack *stack, char tag, int j)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (stack->stack_c[i] != stack->stack_a[k] && k < stack->size - 1)
	{
		i++;
		if (i == stack->mid)
		{
			i = 0;
			k++;
		}
	}
	while (k > 0)
	{
		ft_rotate_up(stack->stack_a, stack->size - j);
		write(1, "ra\n", 3);
		k--;
	}
	ft_pull_to_stack(stack->stack_a, stack->stack_b, stack->size, j - 1);
	write(1, "pb\n", 3);
}

void	ft_do_sort_part2(t_stack *stack, char tag, int j, int rest)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (stack->stack_c[stack->size - i - 1] != stack->stack_b[k])
	{
		i++;
		if (i == stack->mid + rest)
		{
			i = 0;
			k++;
		}
		if (k >= stack->size - 1)
			break ;
	}
	while (k > 0)
	{
		ft_rotate_up(stack->stack_b, stack->size - j - rest);
		write(1, "rb\n", 3);
		k--;
	}
	ft_pull_to_stack(stack->stack_b, stack->stack_a, stack->size, rest + j - 1);
	write(1, "pa\n", 3);
}

void	ft_do_sort_part3(t_stack *stack, char tag, int j, int rest)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (stack->stack_c[i] != stack->stack_a[k] && k < stack->size - 1)
	{
		i++;
		if (i == stack->mid + rest)
		{
			i = 0;
			k++;
		}
	}
	while (k > 0)
	{
		ft_rotate_up(stack->stack_a, stack->size - j - rest);
		write(1, "ra\n", 3);
		k--;
	}
	ft_pull_to_stack(stack->stack_a, stack->stack_b, stack->size, rest + j - 1);
	write(1, "pb\n", 3);
}
