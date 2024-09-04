/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:37:02 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:38:04 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_sub(struct s_stack *b, struct s_list *p)
{
	struct s_list	*tmp;

	tmp = b->top;
	p->prev = tmp->prev;
	p->next = tmp;
	tmp->prev->next = p;
	tmp->prev = p;
	b->top = p;
}

void	pb(struct s_stack *a, struct s_stack *b)
{
	struct s_list	*p;

	p = a->top;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	if ((--a->size) == 0)
		a->top = NULL;
	else
		a->top = p->next;
	if (b->top != NULL)
		pb_sub(b, p);
	else
	{
		b->top = p;
		p->next = p;
		p->prev = p;
	}
	b->size++;
	write(1, "pb\n", 3);
}

void	pa_sub(struct s_stack *a, struct s_list *p)
{
	struct s_list	*tmp;

	tmp = a->top;
	p->prev = tmp->prev;
	p->next = tmp;
	tmp->prev->next = p;
	tmp->prev = p;
	a->top = p;
}

void	pa(struct s_stack *a, struct s_stack *b)
{
	struct s_list	*p;

	p = b->top;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	if ((--b->size) == 0)
		b->top = NULL;
	else
		b->top = p->next;
	if (a->top != NULL)
		pa_sub(a, p);
	else
	{
		a->top = p;
		p->next = p;
		p->prev = p;
	}
	a->size++;
	write(1, "pa\n", 3);
}
