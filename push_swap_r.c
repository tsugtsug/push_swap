/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:16:04 by yokamura          #+#    #+#             */
/*   Updated: 2023/02/05 21:48:12 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(int flag, struct s_list *head)
{
	struct s_list	*p;
	struct s_list	*first;
	struct s_list	*before_last;

	if (flag == 0)
		write(1, "ra\n", 3);
	if (count_list(head) < 2)
		return (6);
	p = head->next;
	first = p->next;
	before_last = head->prev;
	first->prev = head;
	head->next = first;
	head->prev = p;
	p->next = head;
	p->prev = before_last;
	before_last->next = p;
	return (6);
}

int	rb(int flag, struct s_list *head)
{
	struct s_list	*p;
	struct s_list	*first;
	struct s_list	*before_last;

	if (flag == 0)
		write(1, "rb\n", 3);
	if (count_list(head) < 2)
		return (7);
	p = head->next;
	first = p->next;
	before_last = head->prev;
	first->prev = head;
	head->next = first;
	head->prev = p;
	p->next = head;
	p->prev = before_last;
	before_last->next = p;
	return (7);
}

int	rr(struct s_list *head_a, struct s_list *head_b)
{
	write(1, "rr\n", 3);
	ra(1, head_a);
	rb(1, head_b);
	return (8);
}
