/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:33:46 by abettini          #+#    #+#             */
/*   Updated: 2023/04/14 15:58:46 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char a[] = "   -123ciao";
	printf("%d\n", atoi(a));
	printf("%d\n", ft_atoi(a));
	return (0);
}
*/

/*
int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	res;
	char temp;

	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			temp = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'Z')
			temp = str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'z')
			temp = str[i] - 'a' + 10;
		else
			temp = str[i];
		if (temp < base)
			res = res * 10 + str[i];
		else
			break;
		i++;
	}
	return (res);
}
*/