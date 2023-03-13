/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:34:15 by abettini          #+#    #+#             */
/*   Updated: 2023/03/09 10:30:28 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
