/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:21:54 by abettini          #+#    #+#             */
/*   Updated: 2023/02/13 14:21:56 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int		size;

	size = ft_stack_size(stack);
	while (size > 0)
	{
		ft_printf("%d\n", stack->n);
		stack = stack->next;
		size--;
	}
}

void	ft_rev_print_stack(t_stack *stack)
{
	int		size;

	size = ft_stack_size(stack);
	if (stack)
		stack = stack->prev;
	while (size > 0)
	{
		ft_printf("%d\n", stack->n);
		stack = stack->prev;
		size--;
	}
}
