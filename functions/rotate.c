/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:22:08 by manmarti          #+#    #+#             */
/*   Updated: 2021/08/10 18:23:08 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack)
{
	int	aux;
	int	i;

	i = 0;
	aux = stack->a[0];
	while (i < stack->len_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = aux;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	int	aux;
	int	i;

	i = 0;
	aux = stack->b[0];
	while (i < stack->len_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = aux;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	ra(stack);
	rb(stack);
}
