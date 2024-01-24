/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:21:54 by abettini          #+#    #+#             */
/*   Updated: 2023/03/09 10:30:33 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
