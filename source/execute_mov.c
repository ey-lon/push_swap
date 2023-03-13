/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_mov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:48:23 by abettini          #+#    #+#             */
/*   Updated: 2023/03/07 12:10:54 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mov_rr(t_stack **s1, t_stack **s2, int mov_a, int mov_b)
{
	while (mov_a > 0 && mov_b > 0)
	{
		mov_a--;
		mov_b--;
		ft_call_rr(s1, s2);
	}
	while (mov_a-- > 0)
		ft_call_rotate(s1, 'a');
	while (mov_b-- > 0)
		ft_call_rotate(s2, 'b');
}

void	ft_mov_rrr(t_stack **s1, t_stack **s2, int mov_a, int mov_b)
{
	while (mov_a < 0 && mov_b < 0)
	{
		mov_a++;
		mov_b++;
		ft_call_rrr(s1, s2);
	}
	while (mov_a++ < 0)
		ft_call_rev_rotate(s1, 'a');
	while (mov_b++ < 0)
		ft_call_rev_rotate(s2, 'b');
}

void	ft_execute_mov(t_stack **s1, t_stack **s2, int mov_a, int mov_b)
{
	if (mov_a >= 0 && mov_b >= 0)
		ft_mov_rr(s1, s2, mov_a, mov_b);
	else if (mov_a < 0 && mov_b < 0)
		ft_mov_rrr(s1, s2, mov_a, mov_b);
	else if (mov_a >= 0 && mov_b < 0)
	{
		while (mov_a-- > 0)
			ft_call_rotate(s1, 'a');
		while (mov_b++ < 0)
			ft_call_rev_rotate(s2, 'b');
	}
	else if (mov_a < 0 && mov_b >= 0)
	{
		while (mov_a++ < 0)
			ft_call_rev_rotate(s1, 'a');
		while (mov_b-- > 0)
			ft_call_rotate(s2, 'b');
	}
}
