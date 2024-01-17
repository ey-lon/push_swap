/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:35:28 by abettini          #+#    #+#             */
/*   Updated: 2024/01/17 11:30:05 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free_stack(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = ft_stack_size(stack);
	if (size > 0)
	{
		temp = stack->next;
		while (size--)
		{
			free(stack);
			stack = temp;
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
