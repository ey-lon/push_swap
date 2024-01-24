/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:07:29 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:53:31 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_stack_size(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	size = 0;
	if (stack)
	{
		size++;
		temp = stack;
		while (temp->next != stack)
		{
			temp = temp->next;
			size++;
		}
	}
	return (size);
}

bool	ft_order_check(t_stack *stack)
{
	int		size;

	size = ft_stack_size(stack);
	if (stack)
	{
		while (size > 1)
		{
			if (stack->n > stack->next->n)
				return (0);
			stack = stack->next;
			size--;
		}
		return (1);
	}
	return (0);
}
