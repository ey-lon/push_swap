/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:56 by abettini          #+#    #+#             */
/*   Updated: 2024/01/24 10:49:38 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdbool.h>

# ifndef PRINT_PERM
#  define PRINT_PERM 1
# endif

# ifndef SPACES
#  define SPACES "\t\n\v\f\r "
# endif

typedef struct s_stack
{
	int					n;
	struct s_stack		*prev;
	struct s_stack		*next;
}	t_stack;

//print
//void	ft_print_stack(t_stack *stack);
//void	ft_rev_print_stack(t_stack *stack);
//fill_stack
t_stack	*ft_fill_stack(char **mat);
//error_check
bool	ft_error_check(char **mat);
//utils
int		ft_stack_size(t_stack *stack);
bool	ft_order_check(t_stack *stack);
int		ft_get_n_by_pos(t_stack *stack, int pos);
int		ft_get_pos_by_n(t_stack *stack, int n);
t_stack	*ft_find_smallest(t_stack *stack);
//other utils
void	ft_put_node_top(t_stack **stack, t_stack *node, char s_name);
void	ft_free_stack(t_stack *stack);
void	ft_free_mat(char **mat);
int		ft_mat_size(char **mat);
//call operations
void	ft_call_swap(t_stack **stack, char s_name);
void	ft_call_push(t_stack **dest, t_stack **src, char dest_name);
void	ft_call_rotate(t_stack **stack, char s_name);
void	ft_call_rev_rotate(t_stack **stack, char s_name);
void	ft_call_rr(t_stack **stack1, t_stack **stack2);
void	ft_call_rrr(t_stack **stack1, t_stack **stack2);
//operations
void	ft_swap(t_stack **stack);
void	ft_push(t_stack **dest, t_stack **src);
void	ft_rotate(t_stack **stack);
void	ft_rev_rotate(t_stack **stack);
//deal 2 to 5 cases
void	ft_deal_2(t_stack **stack, char s_name);
void	ft_deal_3(t_stack **stack, char s_name);
void	ft_deal_4_5(t_stack **s1, t_stack **s2, char s1_name, char s2_name);
//deal 6+ cases
void	ft_deal_6plus(t_stack **s1, t_stack **s2);
void	ft_execute_mov(t_stack **s1, t_stack **s2, int mov_a, int mov_b);
//lis
void	ft_lis(t_stack **s1, t_stack **s2);
void	ft_intset(int **arr, int value, int size);
int		ft_find_max_i(int *arr, int size);
int		ft_find_int(int *arr, int size, int value);
//mov_a and mov_b
int		*ft_mov_a(t_stack *s1, t_stack *s2, int size);
int		*ft_mov_b(int size);
#endif
