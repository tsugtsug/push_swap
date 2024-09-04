/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:39:34 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:39:56 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(struct s_stack *a)
{
	struct s_list	*p;

	if (a->size == 0 || a->size == 1)
		return ;
	p = a->top;
	a->top = p->next;
	write(1, "ra\n", 3);
}

void	rra(struct s_stack *a)
{
	struct s_list	*p;

	if (a->size == 0 || a->size == 1)
		return ;
	p = a->top;
	a->top = p->prev;
	write(1, "rra\n", 4);
}
