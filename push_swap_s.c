/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:17:48 by yokamura          #+#    #+#             */
/*   Updated: 2023/02/05 21:37:08 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(int flag, struct s_list *head)
{
	struct s_list	*before;
	struct s_list	*first;
	struct s_list	*second;

	if (flag == 0)
		write(1, "sa\n", 3);
	if (count_list(head) == 0 || count_list(head) == 1)
		return (1);
	first = head->next;
	second = first->next;
	before = second->next;
	first->next = before;
	first->prev = second;
	second->next = first;
	second->prev = head;
	head->next = second;
	before->prev = first;
	return (1);
}

int	sb(int flag, struct s_list *head)
{
	struct s_list	*before;
	struct s_list	*first;
	struct s_list	*second;

	if (flag == 0)
		write(1, "sb\n", 3);
	if (count_list(head) == 0 || count_list(head) == 1)
		return (2);
	first = head->next;
	second = first->next;
	before = second->next;
	first->next = before;
	first->prev = second;
	second->next = first;
	second->prev = head;
	head->next = second;
	before->prev = first;
	return (2);
}

int	ss(struct s_list *head_a, struct s_list *head_b)
{
	write(1, "ss\n", 3);
	sa(1, head_a);
	sb(1, head_b);
	return (3);
}
