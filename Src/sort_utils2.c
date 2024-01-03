/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:18:54 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/16 17:28:30 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	sort_4(t_stack **a, t_stack **b)
{
	if (!is_max(a, (*b)->content))
	{
		ft_push(b, a, 'a');
		ft_rotate(a, 'a');
	}
	else if (!is_min(a, (*b)->content))
		ft_push(b, a, 'a');
	else if ((*b)->index > (*a)->index && (*b)->index < (*a)->next->index)
	{
		ft_rotate(a, 'a');
		ft_push(b, a, 'a');
	}
	else
	{
		ft_reverse(a, 'a');
		ft_push(b, a, 'a');
	}
}

void	sort_4in5(t_stack **a, t_stack **b)
{
	int	aux;

	aux = 0;
	if (!is_max(a, (*b)->content) || !is_min(a, (*b)->content))
	{
		if (!is_max(a, (*b)->content))
			search_min(a, 'a', 0, &aux);
		else
			search_min(a, 'a', (*b)->index + 1, &aux);
		ft_push(b, a, 'a');
	}
	else if (get_index(*a, (*b)->index - 1)
		< ft_stack_size(*a) / 2)
	{
		while ((*b)->index > (*a)->index)
			ft_rotate(a, 'a');
		ft_push(b, a, 'a');
	}
	else
	{
		while ((*a)->index != (*b)->index + 1)
			ft_reverse(a, 'a');
		ft_push(b, a, 'a');
	}
}
