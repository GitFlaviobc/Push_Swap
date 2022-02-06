/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort_parts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:19:55 by fbonini           #+#    #+#             */
/*   Updated: 2021/12/04 16:05:26 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_get_mid(t_stack *stack, int loop)
{
	if (loop == 1)
		ft_initial_mids(stack);
	else if (loop == 2)
		ft_mid_mids(stack);
	else if (loop == 3)
		ft_last_mids(stack);
	stack->counter++;
}

void	ft_sort_part1(t_stack *stack, char tag, int i)
{
	int	j;

	j = 0;
	while (j < stack->size * 0.95)
	{
		ft_get_mid(stack, i);
		ft_do_sort_part1(stack, tag, j);
		j++;
	}
}

void	ft_sort_part2(t_stack *stack, char tag, int i)
{
	int	j;

	j = 0;
	while (j < stack->size * 0.9)
	{
		ft_get_mid(stack, i);
		ft_do_sort_part2(stack, tag, j, stack->size * 0.05);
		j++;
	}
}

void	ft_sort_part3(t_stack *stack, char tag, int i)
{
	int	j;

	j = 0;
	while (j < stack->size * 0.95)
	{
		ft_get_mid(stack, i);
		ft_do_sort_part3(stack, tag, j, stack->size * 0.05);
		j++;
	}
}
