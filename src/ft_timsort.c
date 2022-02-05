/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 14:30:05 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/29 16:31:34 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_merge_rest(t_stack *stack, int *arr, int size, int index)
{
	while (index < size)
	{
		stack->stack_c[stack->index] = arr[index];
		stack->index++;
		index++;
	}
}

void	ft_do_merge(t_stack *stack, int *arr_1, int *arr_2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	stack->index = stack->lower;
	while (i < stack->size_1 && j < stack->size_2)
	{
		if (arr_1[i] <= arr_2[j])
		{
			stack->stack_c[stack->index] = arr_1[i];
			i++;
		}
		else
		{
			stack->stack_c[stack->index] = arr_2[j];
			j++;
		}
		stack->index++;
	}
	if (i < stack->size_1)
		ft_merge_rest(stack, arr_1, stack->size_1, i);
	if (j < stack->size_2)
		ft_merge_rest(stack, arr_2, stack->size_2, j);
}

void	ft_merge(t_stack *stack)
{
	int	*arr_1;
	int	*arr_2;

	stack->size_1 = stack->mid - stack->lower + 1;
	stack->size_2 = stack->uper - stack->mid;
	if (ft_alloc_blocks(&arr_1, &arr_2, stack))
	{
		free(arr_1);
		free(arr_2);
		ft_free_stack(stack);
		ft_error();
	}
	ft_prepare_block(stack, arr_1, arr_2);
	ft_do_merge(stack, arr_1, arr_2);
	free(arr_1);
	free(arr_2);
}

void	ft_timsort(t_stack *stack)
{
	int	block;

	block = 32;
	ft_insertion_sort(stack, block);
	while (block < stack->size)
	{
		stack->lower = 0;
		while (stack->lower < stack->size)
		{
			ft_pick_min(stack, stack->lower + (2 * block) - 1);
			stack->mid = stack->lower + block - 1;
			if (stack->mid < stack->uper)
				ft_merge(stack);
			stack->lower = stack->lower + (2 * block);
		}
		block = 2 * block;
	}
}
