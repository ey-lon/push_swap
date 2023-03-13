/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:32:34 by abettini          #+#    #+#             */
/*   Updated: 2023/02/13 16:32:36 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_rotate(t_stack **stack, char s_name)
{
	ft_rotate(stack);
	if (PRINT_PERM == 1)
		ft_printf("r%c\n", s_name);
}

void	ft_call_rev_rotate(t_stack **stack, char s_name)
{
	ft_rev_rotate(stack);
	if (PRINT_PERM == 1)
		ft_printf("rr%c\n", s_name);
}

void	ft_call_rr(t_stack **stack1, t_stack **stack2)
{
	ft_rotate(stack1);
	ft_rotate(stack2);
	if (PRINT_PERM == 1)
		ft_printf("rr\n");
}

void	ft_call_rrr(t_stack **stack1, t_stack **stack2)
{
	ft_rev_rotate(stack1);
	ft_rev_rotate(stack2);
	if (PRINT_PERM == 1)
		ft_printf("rrr\n");
}
