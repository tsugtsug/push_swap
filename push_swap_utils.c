/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:24:12 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/13 21:21:43 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_list_double_linked(struct s_stack *a)
{
	struct s_list	*p;
	struct s_list	*tmp;
	struct s_list	*first;

	p = a->top;
	first = p;
	while (1)
	{
		tmp = p;
		p = p->next;
		if (p != NULL)
			p->prev = tmp;
		else
		{
			first->prev = tmp;
			tmp->next = first;
			break ;
		}
	}
}

void	flag_init(struct s_stack *a)
{
	struct s_list	*p;
	struct s_list	*until;

	p = a->top;
	until = p;
	while (p->next != until)
	{
		p->flag = 0;
		p = p->next;
	}
	p->flag = 0;
}

void	stack_init(struct s_stack *a, struct s_stack *b)
{
	a->top = NULL;
	b->top = NULL;
	a->size = 0;
	b->size = 0;
}
