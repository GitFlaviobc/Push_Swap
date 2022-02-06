/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:33:30 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/29 16:30:49 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_do_insertion_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	temp;

	i = stack->lower + 1;
	while (i <= stack->uper)
	{
		temp = stack->stack_c[i];
		j = i - 1;
		while (j >= stack->lower && stack->stack_c[j] > temp)
		{
			stack->stack_c[j + 1] = stack->stack_c[j];
			j--;
		}
		stack->stack_c[j + 1] = temp;
		i++;
	}
}

void	ft_insertion_sort(t_stack *stack, int block)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		stack->lower = i;
		ft_pick_min(stack, i + block - 1);
		ft_do_insertion_sort(stack);
		i = i + block;
	}
}
