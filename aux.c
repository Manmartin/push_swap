/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:21:16 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 16:11:00 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(-1);
}

void	sort_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[1] > s->a[2] && s->a[0] > s->a[2])
	{
		sa(s);
		rra(s);
	}
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] < s->a[2])
	{
		rra(s);
		sa(s);
	}
	else if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[0] > s->a[2])
		ra(s);
	else if (s->a[0] < s->a[1] && s->a[1] > s->a[2] && s->a[0] > s->a[2])
		rra(s);
	else if (s->a[0] > s->a[1] && s->a[1] < s->a[2] && s->a[0] < s->a[2])
		sa(s);
}

void	sort_b(t_stack *s)
{
	if (s->len_b == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s);
		pa(s);
		pa(s);
	}
	else if (s->len_b == 1)
		pa(s);
}

int	is_sorted(t_stack *stack)
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

int	get_last_bit(int number)
{
	int	bit;

	bit = 32;
	while (--bit > 0)
	{
		if (number & (1 << bit))
			return (bit);
	}
	return (bit);
}
