/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmarti <manmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:43:23 by manmarti          #+#    #+#             */
/*   Updated: 2021/05/24 16:36:19 by manmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_stack {
	int	len;
	int	*a;
	int	*b;
}	t_stack;

void	make_stack(int nargs, t_stack *stack, char **args);

void	put_error(char *msg);

#endif