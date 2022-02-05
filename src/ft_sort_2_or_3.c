/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2_or_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:47:37 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/28 17:05:39 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_two_sort(int *stack)
{
	if (stack[0] > stack[1])
		ft_swap(stack, 0);
	write(1, "sa\n", 3);
}

int	ft_three_check(int *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j <= 2)
	{
		if (stack[0] < stack[j])
			i = i + j;
		else
			i = i - j;
		j++;
	}
	if (stack[1] < stack[2])
		i = i + 5;
	else
		i = i - 5;
	return (i);
}

void	ft_do_sort_three(int *stack, int i)
{
	if (i == -8 || i == 2)
	{
		ft_rotate_up(stack, 3);
		write(1, "ra\n", 3);
	}
	else if (i == -2 || i == -6)
	{
		ft_rotate_down(stack, 3);
		write(1, "rra\n", 4);
	}
	if (i == -2 || i == -8 || i == 6)
	{
		ft_swap(stack, 0);
		write(1, "sa\n", 3);
	}
}

void	ft_three_sort(int *stack)
{
	int	i;

	i = ft_three_check(stack);
	ft_do_sort_three(stack, i);
}
