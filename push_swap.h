/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:28:59 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/13 21:11:38 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define ATOI_M 2147483647

struct s_list
{
	int				flag;
	int				value;
	int				order;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

struct s_stack
{
	int				size;
	struct s_list	*top;
}	t_stack;

void	stack_init(struct s_stack *a, struct s_stack *b);
void	make_list(int argc, char **argv, struct s_stack *a);
void	flag_init(struct s_stack *a);

char	**ft_split(char const *s, char c);
int		ft_atoi_except_str(char *str);
void	make_list_double_linked(struct s_stack *a);
int		get_stack_size(struct s_stack *stack);

void	is_duplicated(struct s_stack *a);
void	print_error_and_exit(void);
void	free_words(char **words);

void	num_to_order(struct s_stack *a);

void	is_sorted(struct s_stack *a);
int		is_sorted_pendent(struct s_stack *a);

void	push_swap(struct s_stack *a, struct s_stack *b);
void	push_swap_for_trois(struct s_stack *a);
void	push_swap_for_cinq(struct s_stack *a, struct s_stack *b);

void	sa(struct s_stack *a);
void	ra(struct s_stack *a);
void	rra(struct s_stack *a);
void	pa(struct s_stack *a, struct s_stack *b);
void	pb(struct s_stack *a, struct s_stack *b);

void	print_every_number2(struct s_stack *stack);
void	print_every_order2(struct s_stack *stack);
void	print_every_flag(struct s_stack *stack);

#endif
