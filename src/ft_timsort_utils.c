/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timsort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 16:34:49 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/30 17:23:20 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pick_min(t_stack *stack, int block)
{
	if (stack->size - 1 < block)
		stack->uper = stack->size - 1;
	else
		stack->uper = block;
}

int	ft_alloc_blocks(int **arr_1, int **arr_2, t_stack *stack)
{
	*arr_1 = (int *) malloc(sizeof(int) * stack->size_1);
	if (!arr_1)
		return (1);
	*arr_2 = (int *) malloc(sizeof(int) * stack->size_2);
	if (!arr_2)
		return (1);
	return (0);
}

void	ft_prepare_block(t_stack *stack, int *arr_1, int *arr_2)
{
	int	i;

	i = 0;
	while (i < stack->size_1)
	{
		arr_1[i] = stack->stack_c[stack->lower + i];
		i++;
	}
	i = 0;
	while (i < stack->size_2)
	{
		arr_2[i] = stack->stack_c[stack->mid + 1 + i];
		i++;
	}
}
