/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:26:51 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/11 22:00:33 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_every_number2(struct s_stack *stack)
{
	struct s_list	*p;
	struct s_list	*until;

	p = stack->top;
	if (p == NULL)
		return ;
	until = p;
	printf("-----\n");
	while (p->next != until)
	{
		printf("%d\n", p->value);
		p = p->next;
	}
	printf("%d\n", p->value);
	printf("-----\n");
}

void	print_every_order2(struct s_stack *stack)
{
	struct s_list	*p;
	int				i;

	p = stack->top;
	if (p == NULL)
		return ;
	printf("-----\n");
	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", p->order);
		p = p->next;
		i++;
	}
	printf("-----\n");
}

void	print_every_flag(struct s_stack *stack)
{
	struct s_list	*p;
	int				i;

	p = stack->top;
	if (p == NULL)
		return ;
	printf("-----\n");
	i = 0;
	while (i < stack->size)
	{
		printf("%d\n", p->flag);
		p = p->next;
		i++;
	}
	printf("-----\n");
}
