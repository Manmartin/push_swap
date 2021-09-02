/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:20:31 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 14:19:06 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack)
{
	int	aux;
	int	i;

	i = stack->len_a - 1;
	aux = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = aux;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	int	aux;
	int	i;

	i = stack->len_b - 1;
	aux = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = aux;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
