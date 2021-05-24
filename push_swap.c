/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:56:53 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/24 18:17:42 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	testing(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->len)
	{
		printf("%i\n", stack->a[i]);
		i++;
	}
	free(stack->a);
	system("leaks push_swap");
}
*/
int	main(int nargs, char **args)
{
	t_stack	stack;

	if (nargs == 1)
		put_error("Error\n");
	else if (nargs == 2)
		make_stack(nargs, &stack, ft_split(args[1], ' '));
	else
		make_stack(nargs, &stack, ++args);
	/*
	testing(&stack);
	*/
	return (0);
}
