/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:53:54 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:48 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack)
{
	int	i;

	if (stack->len_b > 0)
	{
		i = stack->len_a - 1;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
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
	}
}

void	pb(t_stack *stack)
{
	int	i;

	if (stack->len_a > 0)
	{
		i = stack->len_b - 1;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
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
	}
}
