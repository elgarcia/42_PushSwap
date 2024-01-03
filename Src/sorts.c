/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:08:37 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/16 17:28:04 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	sort_3(t_stack **a, char stack)
{
	while (!is_ordered(*a))
	{
		if ((*a)->content > (*a)->next->content)
		{
			if ((*a)->content > ft_stacklast(*a)->content)
				ft_rotate(a, 'a');
			else
				ft_swap(a, stack);
		}
		else if (((*a)->content > ft_stacklast(*a)->content)
			|| ((*a)->content < (*a)->next->content
				&& (*a)->content < ft_stacklast(*a)->content))
			ft_reverse(a, stack);
		else
			ft_rotate(a, stack);
	}
}

void	sort_5(t_stack **a, t_stack **b)
{
	while (ft_stack_size(*a) > 3)
		ft_push(a, b, 'b');
	sort_3(a, 'a');
	clean_b_5(a, b);
}

void	sort_big(t_stack **a, t_stack **b, int size)
{
	reduce_stack(a, b, size);
	clean_b(a, b, size);
}
