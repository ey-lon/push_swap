/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:44:13 by abettini          #+#    #+#             */
/*   Updated: 2024/01/17 11:31:05 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_op2(char *comm, t_stack **a, t_stack **b)
{
	int	err;

	err = 0;
	if (!ft_strncmp(comm, "ra\n", 4))
		ft_rotate(a);
	else if (!ft_strncmp(comm, "rb\n", 4))
		ft_rotate(b);
	else if (!ft_strncmp(comm, "rr\n", 4))
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (!ft_strncmp(comm, "rra\n", 5))
		ft_rev_rotate(a);
	else if (!ft_strncmp(comm, "rrb\n", 5))
		ft_rev_rotate(b);
	else if (!ft_strncmp(comm, "rrr\n", 5))
	{
		ft_rev_rotate(a);
		ft_rev_rotate(b);
	}
	else
		err = 1;
	return (err);
}

int	ft_op1(char *comm, t_stack **a, t_stack **b)
{
	int	err;

	err = 0;
	if (!ft_strncmp(comm, "sa\n", 4))
		ft_swap(a);
	else if (!ft_strncmp(comm, "sb\n", 4))
		ft_swap(b);
	else if (!ft_strncmp(comm, "ss\n", 4))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else if (!ft_strncmp(comm, "pa\n", 4))
		ft_push(a, b);
	else if (!ft_strncmp(comm, "pb\n", 4))
		ft_push(b, a);
	else
		err = ft_op2(comm, a, b);
	return (err);
}

int	ft_exec(t_stack **a, t_stack **b)
{
	int		check;
	char	*command;

	check = 1;
	while (check > 0)
	{
		command = get_next_line(STDIN_FILENO);
		if (command)
		{
			if (ft_op1(command, a, b))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				check = -1;
			}
			free(command);
		}
		else
			check = 0;
	}
	return (check);
}

void	ft_checker(char **mat)
{
	t_stack	*a;
	t_stack	*b;

	if (ft_error_deal(mat))
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else
	{
		a = ft_fill_stack(mat);
		b = NULL;
		if (ft_exec(&a, &b) != -1)
		{
			if (ft_order_check(a) && !ft_stack_size(b))
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
		}
		if (a)
			ft_free_stack(a);
		if (b)
			ft_free_stack(b);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		av = ft_split_2(av[1], SPACES);
		if (av)
		{
			if (*av)
			{
				ft_checker(av);
			}
			ft_free_mat(av);
		}
	}
	else if (ac > 2)
	{
		ft_checker(av + 1);
	}
	return (0);
}
