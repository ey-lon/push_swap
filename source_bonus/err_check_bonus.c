/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:19:31 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:55:46 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static bool	ft_int_limit_check(char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (!(res * sign >= INT_MIN && res * sign <= INT_MAX));
}

static bool	ft_int_type_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static bool	ft_double_check(int n, char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		if (ft_atoi(mat[i]) == n)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

bool	ft_error_check(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		if (ft_int_type_check(mat[i]))
			return (1);
		if (ft_int_limit_check(mat[i]))
			return (1);
		if (ft_double_check(ft_atoi(mat[i]), &(mat[i + 1])))
			return (1);
		i++;
	}
	return (0);
}
