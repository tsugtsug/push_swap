/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:28:33 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/13 21:17:21 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	struct s_stack	a;
	struct s_stack	b;

	if (argc > 1)
	{
		stack_init(&a, &b);
		make_list(argc, argv, &a);
		num_to_order(&a);
		if (a.size == 3)
		{
			push_swap_for_trois(&a);
			is_sorted(&a);
		}
		if (a.size == 5)
		{
			push_swap_for_cinq(&a, &b);
			is_sorted(&a);
		}
		push_swap(&a, &b);
		is_sorted(&a);
		exit(0);
	}
	return (0);
}
