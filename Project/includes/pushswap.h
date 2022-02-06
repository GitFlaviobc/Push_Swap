/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:53:41 by fbonini-          #+#    #+#             */
/*   Updated: 2021/12/04 16:24:40 by fbonini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_c;
	int	size_1;
	int	size_2;
	int	size;
	int	max_numb;
	int	min_numb;
	int	uper;
	int	mid;
	int	lower;
	int	counter;
	int	index;
}			t_stack;

void	ft_check_args(int argc, char **argv);
void	ft_check_valid_arg(char *argv);
void	ft_check_duplicate(char **argv, char *to_check, int argc, int index);
void	ft_zero_check(char **argv, int check);
int		ft_not_sorted(int *stack_a, int size);

void	ft_timsort(t_stack *stack);
void	ft_insertion_sort(t_stack *stack, int block);
void	ft_pick_min(t_stack *stack, int block);
int		ft_alloc_blocks(int **arr_1, int **arr_2, t_stack *stack);
void	ft_alloc_stack(t_stack *stack, int size);
void	ft_prepare_block(t_stack *stack, int *arr_1, int *arr_2);

void	ft_free_stack(t_stack *stack);
void	ft_error(void);

void	ft_two_sort(int *stack_a);
void	ft_three_sort(int *stack);

void	ft_stack_sort(t_stack *stack);

int		ft_get_min_numb(int	*arr, int max, int *index);
int		ft_get_max_numb(int	*arr, int max, int *index);

void	ft_get_mid(t_stack *stack, int loop);
void	ft_initial_mids(t_stack *stack);
void	ft_mid_mids(t_stack *stack);
void	ft_last_mids(t_stack *stack);

void	ft_sort_part1(t_stack *stack, char tag, int i);
void	ft_sort_part2(t_stack *stack, char tag, int i);
void	ft_sort_part3(t_stack *stack, char tag, int i);

void	ft_do_sort_part1(t_stack *stack, char tag, int j);
void	ft_do_sort_part2(t_stack *stack, char tag, int j, int rest);
void	ft_do_sort_part3(t_stack *stack, char tag, int j, int rest);

void	ft_big_sort(t_stack *stack);

int		ft_find_position(t_stack *stack, int size, int a_pos);
void	ft_pick_rotation(t_stack *stack, int i);
void	ft_rotate_stack_a(t_stack *stack, char rotation, int i);
void	ft_rotate_stack_b(t_stack *stack, char rotation, int i);
void	ft_final_rotation(t_stack *stack);

void	ft_swap(int *stack, int index);
void	ft_rotate_up(int *stack, int max);
void	ft_rotate_down(int *stack, int max);
void	ft_pull_to_stack(int *stack_01, int *stack_02, int max_01, int max_02);

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
double	ft_atod(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t len);

#endif
