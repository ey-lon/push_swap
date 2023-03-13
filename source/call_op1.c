/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_op1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:32:34 by abettini          #+#    #+#             */
/*   Updated: 2023/02/13 16:32:36 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_swap(t_stack **stack, char s_name)
{
	ft_swap(stack);
	if (PRINT_PERM == 1)
		ft_printf("s%c\n", s_name);
}

void	ft_call_push(t_stack **dest, t_stack **src, char dest_name)
{
	ft_push(dest, src);
	if (PRINT_PERM == 1)
		ft_printf("p%c\n", dest_name);
}
