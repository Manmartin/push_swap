/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:23:00 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 13:23:01 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int nargs, char **args)
{
	t_stack	stack;

	if (nargs == 1)
		return (0);
	else if (nargs == 2)
		make_stack(nargs, &stack, ft_split(args[1], ' '));
	else if (nargs > 2)
		make_stack(nargs, &stack, ++args);
	sort_stack(&stack);
	return (0);
}
