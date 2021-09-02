/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:20:42 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 14:18:17 by manmarti         ###   ########.fr       */
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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	sa(stack);
	sb(stack);
}
