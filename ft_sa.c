/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:41:43 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:42:02 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(struct s_stack *a)
{
	struct s_list	*p;
	struct s_list	*q;
	struct s_list	*r;
	struct s_list	*s;

	if (a->size <= 1)
		return ;
	p = a->top;
	q = p->next;
	r = p->prev;
	s = q->next;
	p->next = s;
	p->prev = q;
	q->next = p;
	q->prev = r;
	r->next = q;
	s->prev = p;
	a->top = q;
	write(1, "sa\n", 3);
}
