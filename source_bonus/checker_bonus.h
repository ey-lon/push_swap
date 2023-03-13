/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:56 by abettini          #+#    #+#             */
/*   Updated: 2023/03/09 10:31:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "../Libft/libft.h"

typedef struct s_stack
{
	int					n;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

//fill_stack
t_stack	*ft_fill_stack(char **mat);
//error_deal
int		ft_error_deal(char **mat);
//utils
int		ft_stack_size(t_stack *stack);
int		ft_order_check(t_stack *stack);
//print
void	ft_print_stack(t_stack *stack);
void	ft_rev_print_stack(t_stack *stack);
//other utils
void	ft_free_stack(t_stack *stack);
void	ft_free_mat(char **mat);
int		ft_count_str(char **mat);
//operations
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);
#endif
