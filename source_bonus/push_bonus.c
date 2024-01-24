/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:31:33 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:53:09 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_self_link(t_stack **stack)
{
	(*stack)->next = *stack;
	(*stack)->prev = *stack;
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	if (*src)
	{
		temp = *src;
		if (ft_stack_size(*src) >= 2)
		{
			(*src)->next->prev = (*src)->prev;
			(*src)->prev->next = (*src)->next;
			*src = (*src)->next;
		}
		else
			*src = NULL;
		if (*dest)
		{
			temp->next = *dest;
			temp->prev = (*dest)->prev;
			(*dest)->prev->next = temp;
			(*dest)->prev = temp;
		}
		else
			ft_self_link(&temp);
		*dest = temp;
	}
}
//-------------------------------------------
//il prev del nodo 2 di b deve puntare all'ultimo di b
//il next dell'ultimo nodo di b deve puntare al nodo 2 di b
//il prev del nodo 1 di a deve puntare al nodo 1 di b
//il next dell'ultimo nodo di a deve puntare al nodo 1 di b
//il prev del nodo 1 di b deve puntare all'ultimo nodo di a
//il next del nodo 1 di b deve puntare al nodo di a
