/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:04:58 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/13 21:11:23 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_words(char **words)
{
	int	i;

	i = 0;
	while (words[i] != NULL)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

void	print_error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	is_duplicated(struct s_stack *a)
{
	struct s_list	*p;
	struct s_list	*q;
	int				value;

	p = a->top;
	while (p->next != NULL)
	{
		value = p->value;
		q = p;
		while (q->next != NULL)
		{
			q = q->next;
			if (value == q->value)
				print_error_and_exit();
		}
		p = p->next;
	}
}
