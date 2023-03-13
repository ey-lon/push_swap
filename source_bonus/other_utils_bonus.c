/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:35:28 by abettini          #+#    #+#             */
/*   Updated: 2023/03/09 10:30:24 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free_stack(t_stack *stack)
{
	int		size;
	int		i;
	t_stack	*temp;

	size = ft_stack_size(stack);
	if (size > 0)
	{
		temp = stack->next;
		i = 0;
		while (i < size)
		{
			free(stack);
			stack = temp;
			i++;
			if (i < size)
				temp = temp->next;
		}
	}
}

void	ft_free_mat(char **mat)
{
	int	y;

	y = 0;
	if (mat)
	{
		while (mat[y])
		{
			free(mat[y]);
			y++;
		}
		free(mat);
	}
}

int	ft_count_str(char **mat)
{
	int	i;

	i = 0;
	if (mat)
	{
		while (mat[i])
			i++;
	}
	return (i);
}
