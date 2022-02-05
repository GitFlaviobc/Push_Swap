/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini- <fbonini-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:04:28 by fbonini-          #+#    #+#             */
/*   Updated: 2021/11/28 17:19:48 by fbonini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_check_limits(char *argv)
{
	double	check;

	check = ft_atod(argv);
	if (check > INT_MAX || check < INT_MIN)
		ft_error();
}

void	ft_zero_check(char **argv, int check)
{
	if (argv[check][0] == '0')
		argv[check] = "0";
	if (argv[check][0] == '-' && argv[check][1] == '0')
		argv[check] = "0";
}

void	ft_check_duplicate(char **argv, char *to_check, int argc, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(argv[i]);
	while (i <= argc)
	{
		if (i != index && ft_strncmp(argv[i], to_check, 11) == 0)
			ft_error();
		i++;
	}
}

void	ft_check_valid_arg(char *argv)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(argv);
	if (argv[i] == '-' && size > 1)
		i++;
	while (i < size)
	{
		if (ft_isdigit(argv[i]) == 0)
			ft_error();
		i++;
	}
	if (size >= 10)
		ft_check_limits(argv);
}

void	ft_check_args(int argc, char **argv)
{
	int	check;

	check = 1;
	while (check <= argc)
	{
		ft_zero_check(argv, check);
		ft_check_valid_arg(argv[check]);
		ft_check_duplicate(argv, argv[check], argc, check);
		check++;
	}
}
