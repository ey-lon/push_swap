/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:34:15 by abettini          #+#    #+#             */
/*   Updated: 2023/03/07 12:01:40 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

void	ft_rev_rotate(t_stack **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}
