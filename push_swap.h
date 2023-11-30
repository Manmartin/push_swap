/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:23:19 by manmarti          #+#    #+#             */
/*   Updated: 2021/09/02 15:46:48 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_stack {
	int	len_a;
	int	len_b;
	int	*a;
	int	*b;
}	t_stack;

void	make_stack(int nargs, t_stack *stack, char **args);

void	put_error(char *msg);
void	sort_three(t_stack *s);
void	sort_b(t_stack *s);
int		is_sorted(t_stack *stack);
int		get_last_bit(int number);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);

void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);

void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);

void	sort_stack(t_stack *stack);

#endif