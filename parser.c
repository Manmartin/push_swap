/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:22:54 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 19:50:55 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ptrlen(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static void	split_free(char **list)
{
	char	**aux;

	aux = list;
	while (*list)
	{
		free(*list);
		list++;
	}
	free(aux);
}

static int	parser_atoi(char *str, t_stack *stack, int n)
{
	long double	sign;
	long double	number;

	number = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
		if (*str == 0)
			put_error("Error\n");
	}
	while (*str >= 48 && *str <= 57)
		number = number * 10 + (*str++ - '0');
	if (*str || number * sign > INT_MAX || number * sign < INT_MIN)
		return (0);
	stack->a[n] = number * sign ;
	return (1);
}

static int	are_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->len_a)
	{
		while (j < stack->len_a)
		{
			if (stack->a[i] == stack->a[j])
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

void	make_stack(int nargs, t_stack *stack, char **args)
{
	int	n;

	n = ptrlen(args);
	stack->len_a = n;
	stack->len_b = 0;
	stack->a = (int *)ft_calloc(sizeof(int), n);
	stack->b = (int *)ft_calloc(sizeof(int), n);
	if (!stack->a || !stack->b)
		put_error("Error\n");
	while (n--)
		if (!parser_atoi(args[n], stack, n))
			put_error("Error\n");
	if (nargs == 2)
		split_free(args);
	if (are_duplicates(stack))
		put_error("Error\n");
}
