/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listmaker_and_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:40 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/13 21:18:37 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_list	*lst_get_last(struct s_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	new_connect_to_a(struct s_stack *a, char **words)
{
	int				i;
	struct s_list	*p;
	struct s_list	*tmp;

	i = 0;
	tmp = NULL;
	while (words[i] != NULL)
	{
		p = (struct s_list *)malloc(sizeof(struct s_list));
		if (p == NULL)
			print_error_and_exit();
		if (i == 0 && a->top == NULL)
			a->top = p;
		else if (i == 0)
		{
			tmp = lst_get_last(a->top);
			tmp->next = p;
		}
		else
			tmp->next = p;
		p->value = ft_atoi_except_str(words[i]);
		p->next = NULL;
		tmp = p;
		i++;
	}
}

void	make_list(int argc, char **argv, struct s_stack *a)
{
	int		i;
	char	**words;

	i = 1;
	while (i < argc)
	{
		words = ft_split(argv[i], ' ');
		new_connect_to_a(a, words);
		free_words(words);
		i++;
	}
	is_duplicated(a);
	make_list_double_linked(a);
	a->size = get_stack_size(a);
}
