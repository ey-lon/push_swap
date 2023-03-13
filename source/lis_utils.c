/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:34:07 by abettini          #+#    #+#             */
/*   Updated: 2023/03/06 11:58:27 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intset(int **arr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*arr)[i] = value;
		i++;
	}
}

int	ft_find_max_i(int *arr, int size)
{
	int	i;
	int	max_i;
	int	temp;

	temp = arr[0];
	max_i = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

int	ft_find_int(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}
