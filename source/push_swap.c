/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:40:27 by abettini          #+#    #+#             */
/*   Updated: 2023/08/03 10:44:18 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(char **mat)
{
	t_stack	*a;
	t_stack	*b;

	if (ft_error_deal(mat))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		a = ft_fill_stack(mat);
		b = NULL;
		if (ft_stack_size(a) == 2)
			ft_deal_2(&a, 'a');
		else if (ft_stack_size(a) == 3)
			ft_deal_3(&a, 'a');
		else if (ft_stack_size(a) > 3 && ft_stack_size(a) <= 5)
			ft_deal_4_5(&a, &b, 'a', 'b');
		else if (ft_stack_size(a) > 5)
			ft_deal_6plus(&a, &b);
		ft_free_stack(a);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_split_2(av[1], SPACES);
		if (*av)
			ft_push_swap(av);
		ft_free_mat(av);
	}
	else if (ac > 2)
		ft_push_swap(av + 1);
	return (0);
}
