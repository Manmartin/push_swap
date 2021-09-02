/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:21:51 by manmarti          #+#    #+#             */
/*   Updated: 2021/08/10 18:26:25 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack)
{
	int	i;

	if (stack->len_b > 0)
	{
		i = stack->len_a - 1;
		while (i >= 0)
		{
			stack->a[i + 1] = stack->a[i];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->len_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->len_a++;
		stack->len_b--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->len_a > 0)
	{
		i = stack->len_b - 1;
		while (i >= 0)
		{
			stack->b[i + 1] = stack->b[i];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->len_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->len_b++;
		stack->len_a--;
		write(1, "pb\n", 3);
	}
}
