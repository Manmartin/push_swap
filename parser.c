/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:57:42 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/24 18:16:52 by manmarti         ###   ########.fr       */
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
		if (*str++ == '-')
			sign = -1;
	while (*str >= 48 && *str <= 57)
		number = number * 10 + (*str++ - '0');
	if (*str || number * sign > INT_MAX || number * sign < INT_MIN)
		return (0);
	stack->a[n] = number;
	return (1);
}

static int	are_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < stack->len)
	{
		while (j < stack->len)
		{
			if (stack->a[i] == stack->a[j])
			{
				free(stack->a);
				return (1);
			}
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
	stack->len = n;
	stack->a = (int *)ft_calloc(sizeof(int), n);
	if (stack == 0)
		put_error("Error\n");
	while (n--)
	{
		if (!parser_atoi(args[n], stack, n))
		{
			if (nargs == 2)
				split_free(args);
			free(stack->a);
			put_error("Error\n");
		}
	}
	if (nargs == 2)
		split_free(args);
	if (are_duplicates(stack))
		put_error("Error\n");
}