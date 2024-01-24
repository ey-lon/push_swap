/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:25:11 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:57:41 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static t_stack	*ft_new_node(t_stack *prev, int n)
{
	t_stack	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = prev;
	node->next = NULL;
	return (node);
}

t_stack	*ft_fill_stack(char **mat)
{
	t_stack	*stack;
	t_stack	*temp;
	int		j;
	int		size;

	size = ft_mat_size(mat);
	stack = ft_new_node(NULL, ft_atoi(mat[0]));
	temp = stack;
	j = 1;
	while (j < size)
	{
		temp->next = ft_new_node(temp, ft_atoi(mat[j]));
		temp = temp->next;
		j++;
	}
	temp->next = stack;
	stack->prev = temp;
	return (stack);
}
