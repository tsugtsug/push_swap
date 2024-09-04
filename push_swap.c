/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:01:56 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:39:52 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_b_empty(struct s_stack *b)
{
	if (b->top == NULL)
		return (1);
	else
		return (0);
}

void	main_sort(struct s_stack *a, struct s_stack *b, int size, int max_fois)
{
	int				i;
	int				j;
	int				num;

	i = 0;
	while (i < max_fois)
	{
		j = 0;
		if (is_sorted_pendent(a) == 0)
			return ;
		while (j < size)
		{
			num = a->top->order;
			if (((num >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (is_b_empty(b) == 0)
			pa(a, b);
		i++;
	}
}

void	push_swap(struct s_stack *a, struct s_stack *b)
{
	int	size;
	int	max_num;
	int	max_fois;

	size = get_stack_size(a);
	max_num = size - 1;
	max_fois = 0;
	while ((max_num >> max_fois) != 0)
		max_fois++;
	main_sort(a, b, size, max_fois);
}
