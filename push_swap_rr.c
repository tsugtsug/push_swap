/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:15:00 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/13 21:21:27 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(int flag, struct s_list *head)
{
	struct s_list	*p;
	struct s_list	*last;
	struct s_list	*next_first;

	if (flag == 0)
		write(1, "rra\n", 4);
	if (count_list(head) < 2)
		return (9);
	p = head->prev;
	last = p->prev;
	next_first = head->next;
	last->next = head;
	head->prev = last;
	head->next = p;
	p->prev = head;
	p->next = next_first;
	next_first->prev = p;
	return (9);
}

int	rrb(int flag, struct s_list *head)
{
	struct s_list	*p;
	struct s_list	*last;
	struct s_list	*next_first;

	if (flag == 0)
		write(1, "rrb\n", 4);
	if (count_list(head) < 2)
		return (10);
	p = head->prev;
	last = p->prev;
	next_first = head->next;
	last->next = head;
	head->prev = last;
	head->next = p;
	p->prev = head;
	p->next = next_first;
	next_first->prev = p;
	return (10);
}

int	rrr(struct s_list *head_a, struct s_list *head_b)
{
	write(1, "rrr\n", 4);
	rra(1, head_a);
	rrb(1, head_b);
	return (11);
}
