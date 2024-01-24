/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:00:35 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:43:51 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_mov_b(int size)
{
	int	i;
	int	*mov_b;

	mov_b = malloc(sizeof(int) * size);
	if (!mov_b)
		return (NULL);
	if (size > 0)
	{
		i = 0;
		while (i < (size / 2))
		{
			mov_b[size - i - 1] = (i + 1) * -1;
			i++;
		}
		i = 0;
		while (i < (size / 2) + 1)
		{
			mov_b[i] = i;
			i++;
		}
	}
	return (mov_b);
}

static int	ft_fill_mov_a(t_stack *s1, int s2_n)
{
	t_stack	*temp;
	int		size;
	int		value;
	int		i;

	size = ft_stack_size(s1);
	if (ft_get_pos_by_n(s1, ft_find_smallest(s1)->n) > size / 2 + 1)
		value = ft_get_pos_by_n(s1, ft_find_smallest(s1)->n) - 1 - size;
	else
		value = ft_get_pos_by_n(s1, ft_find_smallest(s1)->n) - 1;
	temp = s1;
	i = 0;
	while (i++ < size)
	{
		if (s2_n > temp->prev->n && s2_n < temp->n)
		{
			if (ft_get_pos_by_n(s1, temp->n) > size / 2 + 1)
				value = ft_get_pos_by_n(s1, temp->n) - 1 - size;
			else
				value = ft_get_pos_by_n(s1, temp->n) - 1;
		}
		temp = temp->next;
	}
	return (value);
}

int	*ft_mov_a(t_stack *s1, t_stack *s2, int size)
{
	int	*mov_a;
	int	i;

	mov_a = malloc(sizeof(int) * size);
	if (!mov_a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		mov_a[i] = ft_fill_mov_a(s1, s2->n);
		i++;
		s2 = s2->next;
	}
	return (mov_a);
}
