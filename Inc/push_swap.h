/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:52:19 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/15 20:28:14 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* AUXILIAR FUNCTIONS */
t_stack	*ft_stacknew(int content);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_free(t_stack **stack);
int		is_ordered(t_stack *a);
int		ft_stack_size(t_stack *a);
void	assign_index(t_stack **stack);
void	search_min(t_stack **a, char stack, int csize, int *cini);
void	search_max(t_stack **a, char stack, int *cini);
int		get_max(t_stack *a);
int		get_min(t_stack *a, int csize);
int		get_index(t_stack *a, int num);
void	ft_order_rr(t_stack **a);

/* MOVEMENT FUNCTIONS */
void	ft_swap(t_stack **ab, char stack);
void	ft_swap_swap(t_stack **a, t_stack **b);
void	ft_push(t_stack **a, t_stack **b, char stack);
void	ft_rotate(t_stack **a, char stack);
void	ft_reverse(t_stack **a, char stack);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

/* SORT FUNCTIONS */
void	ft_order(t_stack **a, t_stack **b, int argc);
void	sort_3(t_stack **a, char stack);
void	sort_5(t_stack **a, t_stack **b);
void	sort_big(t_stack **a, t_stack **b, int size);

/* AUXILIAR SORTS FUNCTIONS */
void	reduce_stack(t_stack **a, t_stack **b, int size);
int		is_min(t_stack **a, int num);
int		is_max(t_stack **a, int num);
void	clean_b(t_stack **a, t_stack **b, int size);
void	clean_b_5(t_stack **a, t_stack **b);
void	sort_4in5(t_stack **a, t_stack **b);
void	sort_4(t_stack **a, t_stack **b);

#endif