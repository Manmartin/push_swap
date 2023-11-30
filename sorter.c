/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:26:27 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 19:40:27 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	map_stack(t_stack *stack)
{
	int	*new_stack;
	int	i;
	int	j;

	new_stack = (int *)malloc(sizeof(int) * stack->len_a);
	if (new_stack == NULL)
		put_error("Error\n");
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

static void	sort_short(t_stack *stack)
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

static void	optimize_b(t_stack *stack, int next_shift, int last_bit)
{
	int	j;

	j = stack->len_b;
	while (j-- && next_shift <= last_bit && !is_sorted(stack))
	{
		if (stack->b[0] & (1 << (next_shift)))
			pa(stack);
		else
			rb(stack);
	}
}

static void	sort_big(t_stack *stack)
{
	int	shift;
	int	last_bit;
	int	i;

	shift = 0;
	last_bit = get_last_bit(stack->len_a - 1);
	while (shift <= last_bit)
	{
		i = stack->len_a;
		while (i-- && !is_sorted(stack))
		{
			if (stack->a[0] & (1 << shift))
				ra(stack);
			else
				pb(stack);
		}
		optimize_b(stack, shift + 1, last_bit);
		if (is_sorted(stack))
			while (stack->len_b)
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
	free(stack->a);
	free(stack->b);
}
