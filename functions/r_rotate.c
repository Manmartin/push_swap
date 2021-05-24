/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:33:25 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/24 20:35:23 by manmarti         ###   ########.fr       */
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
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
}
