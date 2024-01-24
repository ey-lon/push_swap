/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:35:28 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:35:55 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_node_top(t_stack **stack, t_stack *node, char s_name)
{
	if (node && *stack)
	{
		if (ft_get_pos_by_n(*stack, node->n) \
			> ft_stack_size(*stack) / 2 + 1)
		{
			while (ft_get_pos_by_n(*stack, node->n) != 1)
			{
				ft_call_rev_rotate(stack, s_name);
			}
		}
		else
		{
			while (ft_get_pos_by_n(*stack, node->n) != 1)
			{
				ft_call_rotate(stack, s_name);
			}
		}
	}
}

void	ft_free_stack(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = ft_stack_size(stack);
	if (size > 0)
	{
		temp = stack->next;
		while (size)
		{
			free(stack);
			stack = temp;
			size--;
			if (size)
				temp = temp->next;
		}
	}
}

void	ft_free_mat(char **mat)
{
	int	i;

	if (mat)
	{
		i = 0;
		while (mat[i])
		{
			free(mat[i]);
			i++;
		}
		free(mat);
	}
}

int	ft_mat_size(char **mat)
{
	int	i;

	i = 0;
	if (mat)
	{
		while (mat[i])
		{
			i++;
		}
	}
	return (i);
}
