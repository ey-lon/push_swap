/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:07:29 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:47:24 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_n_by_pos(t_stack *stack, int pos)
{
	while (--pos > 0 && stack)
		stack = stack->next;
	if (stack)
		return (stack->n);
	return (0);
}

int	ft_get_pos_by_n(t_stack *stack, int n)
{
	int	pos;
	int	size;

	pos = 0;
	if (stack)
	{
		pos++;
		size = ft_stack_size(stack);
		while (stack->n != n && pos < size)
		{
			pos++;
			stack = stack->next;
		}
		if (stack->n == n)
			return (pos);
	}
	return (0);
}

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

	if (stack)
	{
		size = ft_stack_size(stack);
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

t_stack	*ft_find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	int		size;
	int		j;

	smallest = NULL;
	if (stack)
	{
		smallest = stack;
		size = ft_stack_size(stack);
		j = 0;
		while (j < size)
		{
			if (stack->n < smallest->n)
				smallest = stack;
			stack = stack->next;
			j++;
		}
	}
	return (smallest);
}
