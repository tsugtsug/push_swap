/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_and_atoi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 18:25:58 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/13 22:23:36 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_max_min(int sign, int sum, int d)
{
	if (sign == 1 && (sum > ATOI_M / 10 || (sum == ATOI_M / 10 && d > 7)))
		print_error_and_exit();
	if (sign == -1 && (sum > ATOI_M / 10 || (sum == ATOI_M / 10 && d > 8)))
		print_error_and_exit();
}

int	ft_atoi_except_str(char *str)
{
	int	i;
	int	sum;
	int	sign;
	int	d;

	i = 0;
	sum = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		print_error_and_exit();
	while (str[i] >= '0' && str[i] <= '9')
	{
		d = str[i++] - '0';
		ft_atoi_max_min(sign, sum, d);
		sum = sum * 10 + d;
	}
	if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		print_error_and_exit();
	return (sum * sign);
}

int	ft_split_sub(char const *s, char c, char **rtn, int j)
{
	int	count;
	int	i;
	int	l;

	count = 0;
	i = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	rtn[j] = (char *)malloc(sizeof(char) * (count + 1));
	if (rtn[j] == NULL)
		print_error_and_exit();
	l = 0;
	i = 0;
	while (s[i] != c && s[i])
		rtn[j][l++] = (char)s[i++];
	rtn[j][l] = '\0';
	return (i);
}

char	**ft_split_main(char const *s, char c, char **rtn)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = ft_split_sub(&s[i], c, rtn, j);
			i = i + k;
			if (k == -1)
				return (NULL);
			j++;
		}
		else
			i++;
	}
	rtn[j] = NULL;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	if (s[0] == '\0' || count == 0)
		print_error_and_exit();
	rtn = (char **)malloc(sizeof(char *) * (count + 1));
	if (rtn == NULL)
		print_error_and_exit();
	rtn = ft_split_main(s, c, rtn);
	return (rtn);
}
