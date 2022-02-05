/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:26:10 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/30 17:37:04 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_get_min_numb(int	*arr, int max, int *index)
{
	int	i;
	int	temp;

	i = 0;
	temp = arr[0];
	while (i <= max)
	{
		if (arr[i] < temp)
		{
			temp = arr[i];
			if (index != NULL)
				*index = i;
		}
		i++;
	}
	if (temp == arr[0] && index != NULL)
		*index = 0;
	return (temp);
}

int	ft_get_max_numb(int	*arr, int max, int *index)
{
	int	i;
	int	temp;

	i = 0;
	temp = arr[0];
	while (i <= max)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
			if (index != NULL)
				*index = i;
		}
		i++;
	}
	return (temp);
}
