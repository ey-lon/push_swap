/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:32:34 by abettini          #+#    #+#             */
/*   Updated: 2023/03/09 10:31:08 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack && (*stack) != (*stack)->next)
	{
		if ((*stack)->next == (*stack)->prev)
			(*stack) = (*stack)->next;
		else
		{
			temp = (*stack)->prev;
			(*stack)->prev = (*stack)->next;
			(*stack)->next = (*stack)->next->next;
			(*stack)->next->prev = (*stack);
			temp->next = (*stack)->prev;
			temp->next->prev = temp;
			temp->next->next = (*stack);
			(*stack) = temp->next;
		}
	}
}

//-------------------------------------------
//
//if (ci solo due nodi)
//	il 2 diventa il primo
//
//else
//	temp punta a 4 (l'ultimo)
//	il prev di 1 punta a 2
//	il next di 1 punta a 3 (il next di 2)
//	il prev di 3 punta a 1
//	il next di 4 (l'ultimo) punta a 2
//	il prev di 2 punta a 4
//	il next di 2 punta a 1
//	stack punta a 2 (il nuovo primo)
//
//-------------------------------------------
//	In caso di piu' di due nodi:
//-------------------------------------------
// ( ... -> 4 -> 1 -> 2 -> 3 -> 4 ->... )
//-------------------------------------------
// il next di 4 deve puntare a 2;
// il prev di 2 deve puntare a 4;
// il next di 2 deve puntare a 1;
// il prev di 1 deve puntare a 2;
// il next di 1 deve puntare a 3;
// il prev di 3 deve puntare a 2;
//-------------------------------------------
//
//-------------------------------------------
//	In caso di due nodi:
//-------------------------------------------
// ( ... -> 2 -> 1 -> 2 ->... )
//-------------------------------------------
// il primo diventa il secondo;
