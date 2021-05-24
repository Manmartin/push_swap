/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:30:56 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/24 18:46:46 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	int	aux;

	if (stack->len_a > 1)
	{
		aux = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = aux;
	}
}

void	sb(t_stack *stack)
{
	int	aux;

	if (stack->len_b > 1)
	{
		aux = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = aux;
	}
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
