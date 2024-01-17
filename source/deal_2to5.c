/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_2to5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:14:06 by abettini          #+#    #+#             */
/*   Updated: 2024/01/17 11:12:38 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_deal_2(t_stack **stack, char s_name)
{
	if ((*stack)->n > (*stack)->next->n)
	{
		ft_call_rotate(stack, s_name);
	}
}

void	ft_deal_3(t_stack **stack, char s_name)
{
	if (!ft_order_check(*stack))
	{
		if ((*stack)->n < (*stack)->next->n)
		{
			ft_call_rev_rotate(stack, s_name);
			if ((*stack)->next->n < (*stack)->n)
				ft_call_swap(stack, s_name);
		}
		else if ((*stack)->n > (*stack)->next->n && \
				(*stack)->n > (*stack)->prev->n)
		{
			if ((*stack)->next->n > (*stack)->prev->n)
			{
				ft_call_swap(stack, s_name);
				ft_call_rev_rotate(stack, s_name);
			}
			else
				ft_call_rotate(stack, s_name);
		}
		else if ((*stack)->n > (*stack)->next->n)
			ft_call_swap(stack, s_name);
	}
}

void	ft_deal_4_5(t_stack **s1, t_stack **s2, char s1_name, char s2_name)
{
	int	s1_size;
	int	j;

	s1_size = ft_stack_size(*s1);
	j = 0;
	while (s1_size > 3 && !ft_order_check(*s1))
	{
		ft_put_node_top(s1, ft_find_smallest(*s1), s1_name);
		if (!ft_order_check(*s1))
		{
			ft_call_push(s2, s1, s2_name);
			s1_size--;
			j++;
		}
	}
	if (s1_size == 3)
		ft_deal_3(s1, s1_name);
	while (j--)
		ft_call_push(s1, s2, s1_name);
}
