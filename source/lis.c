/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:52:42 by abettini          #+#    #+#             */
/*   Updated: 2024/01/17 11:17:46 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_not_lis(t_stack **s1, t_stack **s2, int *lis, int lis_size)
{
	int		s1_size;
	t_stack	*temp;

	s1_size = ft_stack_size(*s1);
	while (s1_size - lis_size > 0)
	{
		temp = *s1;
		while (ft_find_int(lis, lis_size, temp->n))
			temp = temp->next;
		ft_put_node_top(s1, temp, 'a');
		ft_call_push(s2, s1, 'b');
		s1_size--;
	}
}

int	*ft_lis_n(t_stack *s, int *lis_pos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		lis_pos[i] = ft_n_at_pos(s, lis_pos[i] + 1);
		i++;
	}
	return (lis_pos);
}

int	*ft_real_lis_pos(int *lis_pos, int i, int size)
{
	int	temp;
	int	*real_lis_pos;
	int	j;

	real_lis_pos = malloc(sizeof(int) * size);
	if (!real_lis_pos)
		return (NULL);
	temp = i;
	j = 0;
	while (j < size)
	{
		real_lis_pos[j] = temp;
		temp = lis_pos[temp];
		j++;
	}
	free(lis_pos);
	return (real_lis_pos);
}

void	ft_do_lis(t_stack *stack, int **lis_len, int **lis_pos)
{
	int	i;
	int	j;
	int	size;

	size = ft_stack_size(stack);
	ft_intset(lis_pos, -1, size);
	(*lis_len)[0] = 1;
	i = 1;
	while (i < size)
	{
		(*lis_len)[i] = 1;
		j = 0;
		while (j < i)
		{
			if (ft_n_at_pos(stack, i + 1) > ft_n_at_pos(stack, j + 1) \
				&& (*lis_len)[i] <= (*lis_len)[j] + 1)
			{
				(*lis_len)[i] = (*lis_len)[j] + 1;
				(*lis_pos)[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_lis(t_stack **s1, t_stack **s2)
{
	int	*lis_len;
	int	*lis_pos;
	int	max_i;
	int	size;

	size = ft_stack_size(*s1);
	lis_len = malloc(sizeof(int) * size);
	lis_pos = malloc(sizeof(int) * size);
	ft_do_lis(*s1, &lis_len, &lis_pos);
	max_i = ft_find_max_i(lis_len, size);
	lis_pos = ft_real_lis_pos(lis_pos, max_i, lis_len[max_i]);
	lis_pos = ft_lis_n(*s1, lis_pos, lis_len[max_i]);
	ft_push_not_lis(s1, s2, lis_pos, lis_len[max_i]);
	free(lis_pos);
	free(lis_len);
}
