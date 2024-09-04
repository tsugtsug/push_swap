/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_order.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:27:56 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:32:53 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(struct s_stack *stack)
{
	struct s_list	*p;
	struct s_list	*until;
	int				size;

	size = 0;
	p = stack->top;
	until = p;
	while (p->next != until)
	{
		p = p->next;
		size++;
	}
	size++;
	return (size);
}

void	flag_check_and_order(struct s_stack *a, int max, int size)
{
	struct s_list	*p;
	struct s_list	*until;

	p = a->top;
	until = p;
	while (p->next != until && p->value != max)
		p = p->next;
	p->order = size;
	p->flag = 1;
}

void	make_order_accordingto_num(struct s_stack *a, int size)
{
	struct s_list	*p;
	struct s_list	*until;
	int				max;
	int				i;

	until = a->top;
	while (size--)
	{
		i = 0;
		p = a->top;
		while (p->next != until)
		{
			if (p->flag == 0 && i == 0)
			{
				i++;
				max = p->value;
			}
			else if (p->flag == 0 && max < p->value)
				max = p->value;
			p = p->next;
		}
		if (p->flag == 0 && (p->value > max || i == 0))
			max = p->value;
		flag_check_and_order(a, max, size);
	}
}

void	num_to_order(struct s_stack *a)
{
	flag_init(a);
	make_order_accordingto_num(a, get_stack_size(a));
}
