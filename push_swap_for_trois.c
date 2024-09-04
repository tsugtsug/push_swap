/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_for_trois.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:43:21 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:43:50 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_for_trois(struct s_stack *a, struct s_list *p)
{
	p = a->top;
	if (p->order > p->prev->order)
		ra(a);
	else
		sa(a);
}

void	rra_for_trois(struct s_stack *a, struct s_list *p)
{
	p = a->top;
	if (p->order > p->prev->order)
		rra(a);
	else
		sa(a);
}

void	push_swap_for_trois(struct s_stack *a)
{
	int				i;
	int				num;
	struct s_list	*p;

	i = 0;
	while (i++ < 2)
	{
		if (is_sorted_pendent(a) == 0)
			return ;
		p = a->top;
		num = p->order;
		if ((num > p->next->order) && (p->next->order < p->prev->order))
			ra_for_trois(a, p);
		else if ((num < p->next->order) && (p->next->order > p->prev->order))
			rra_for_trois(a, p);
		else
			sa(a);
	}
}
