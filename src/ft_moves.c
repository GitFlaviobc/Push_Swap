/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:34:35 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/30 17:25:03 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(int *stack, int index)
{
	int	temp;

	temp = stack[index];
	stack[index] = stack[index + 1];
	stack[index + 1] = temp;
}

void	ft_rotate_up(int *stack, int max)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[0];
	while (i < max - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[max - 1] = temp;
}

void	ft_rotate_down(int *stack, int max)
{
	int	i;
	int	temp;

	i = max - 1;
	temp = stack[max - 1];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

void	ft_pull_to_stack(int *stack_01, int *stack_02, int max_01, int max_02)
{
	int	i;

	while (max_02 >= 0)
	{
		ft_swap(stack_02, max_02);
		max_02--;
	}
	stack_02[0] = stack_01[0];
	stack_01[0] = 0;
	i = 0;
	while (i < max_01 - 1)
	{
		ft_swap(stack_01, i);
		i++;
	}
}
