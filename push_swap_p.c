/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:16:55 by yokamura          #+#    #+#             */
/*   Updated: 2023/02/05 21:19:37 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(struct s_list *head_a, struct s_list *head_b)
{
	struct s_list	*p;
	struct s_list	*element;

	write(1, "pa\n", 3);
	if (count_list(head_b) == 0)
		return (4);
	element = head_b->next;
	p = element->next;
	p->prev = head_b;
	head_b->next = p;
	p = head_a->next;
	element->next = p;
	element->prev = head_a;
	p->prev = element;
	head_a->next = element;
	return (4);
}

int	pb(struct s_list *head_a, struct s_list *head_b)
{
	struct s_list	*p;
	struct s_list	*element;

	write(1, "pb\n", 3);
	if (count_list(head_a) == 0)
		return (5);
	element = head_a->next;
	p = element->next;
	p->prev = head_a;
	head_a->next = p;
	p = head_b->next;
	element->next = p;
	element->prev = head_b;
	p->prev = element;
	head_b->next = element;
	return (5);
}
