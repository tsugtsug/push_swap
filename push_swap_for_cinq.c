/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_for_cinq.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:55:04 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 23:03:46 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flag_max_min(struct s_stack *a, int max, int min)
{
	struct s_list	*p;
	struct s_list	*until;
	int				i;

	until = a->top;
	p = a->top;
	i = 0;
	while (p->next != until)
	{
		if (max == p->order || min == p->order)
		{
			i++;
			if (max == p->order)
				p->flag = 2;
			else
				p->flag = 1;
		}
		p = p->next;
	}
	if (i == 1 && max == p->order)
		p->flag = 2;
	else if (i == 1 && min == p->order)
		p->flag = 1;
}

void	check_max_min(struct s_stack *a)
{
	struct s_list	*p;
	struct s_list	*until;
	int				max;
	int				min;

	flag_init(a);
	until = a->top;
	p = a->top;
	max = p->order;
	min = p->order;
	while (p->next != until)
	{
		if (max < p->order)
			max = p->order;
		if (min > p->order)
			min = p->order;
		p = p->next;
	}
	if (max < p->order)
		max = p->order;
	if (min > p->order)
		min = p->order;
	flag_max_min(a, max, min);
}

void	push_max_min(struct s_stack *a, struct s_stack *b)
{
	struct s_list	*p;
	int				i;
	int				size;

	i = 0;
	size = a->size;
	while (size-- && i != 2)
	{
		p = a->top;
		if (p->flag == 1 || p->flag == 2)
		{
			i++;
			pb(a, b);
		}
		else
			ra(a);
	}
	if (i != 2)
		pb(a, b);
}

void	push_back_fromb(struct s_stack *a, struct s_stack *b)
{
	if (b->top->flag == 1)
	{
		pa(a, b);
		pa(a, b);
		ra(a);
	}
	else
	{
		pa(a, b);
		ra(a);
		pa(a, b);
	}
}

void	push_swap_for_cinq(struct s_stack *a, struct s_stack *b)
{
	if (is_sorted_pendent(a) == 0)
		return ;
	check_max_min(a);
	push_max_min(a, b);
	push_swap_for_trois(a);
	push_back_fromb(a, b);
}
