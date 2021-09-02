/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:26:27 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 16:14:23 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	map_stack(t_stack *stack)
{
	int	*new_stack;
	int	i;
	int	j;

	new_stack = (int *)malloc(sizeof(int) * stack->len_a);
	i = 0;
	j = 0;
	while (i < stack->len_a)
	{
		new_stack[i] = 0;
		while (j < stack->len_a)
			if (stack->a[i] > stack->a[j++])
				new_stack[i]++;
		i++;
		j = 0;
	}
	free(stack->a);
	stack->a = new_stack;
}

void	sort_short(t_stack *stack)
{
	int	i;
	int	len;	

	i = 0;
	len = stack->len_a;
	if (stack->len_a == 2)
		sa(stack);
	else if (stack->len_a == 3)
		sort_three(stack);
	else
	{
		while (i < len)
		{
			if (stack->a[0] < len - 3)
				pb(stack);
			else
				ra(stack);
			i++;
		}
		sort_three(stack);
		sort_b(stack);
	}
}

void	sort_big(t_stack *stack)
{
	int	shift;
	int	i;

	shift = 0;
	while (!is_sorted(stack))
	{
		i = stack->len_a;
		while (i--)
		{
			if (stack->a[0] & (1 << shift))
				ra(stack);
			else
				pb(stack);
		}
		while (stack->len_b > 0)
			pa(stack);
		shift++;
	}
}

void	sort_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (!is_sorted(stack))
	{
		map_stack(stack);
		if (stack->len_a <= 5)
			sort_short(stack);
		else if (stack->len_a > 5)
			sort_big(stack);
	}
}
