/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:02:48 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:50:26 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(struct s_stack *a)
{
	int				size;
	struct s_list	*p;
	int				num_prev;
	int				i;

	size = get_stack_size(a);
	p = a->top;
	i = 0;
	while (i < size)
	{
		if (i != 0 && (p->order < num_prev))
		{
			write(1, "NG\n", 3);
			exit(1);
		}
		else
			num_prev = p->order;
		p = p->next;
		i++;
	}
	exit(0);
}

int	is_sorted_pendent(struct s_stack *a)
{
	int				size;
	struct s_list	*p;
	int				num_prev;
	int				i;

	size = get_stack_size(a);
	p = a->top;
	i = 0;
	while (i < size)
	{
		if (i != 0 && (p->order < num_prev))
			return (1);
		else
			num_prev = p->order;
		p = p->next;
		i++;
	}
	return (0);
}
