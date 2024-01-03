/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:01:14 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/15 16:31:18 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

int	get_max(t_stack *a)
{
	t_stack	*aux;
	int		index;

	aux = a;
	index = a->index;
	while (aux)
	{
		if (aux->index > index)
			index = aux->index;
		aux = aux->next;
	}
	return (index);
}

int	get_min(t_stack *a, int csize)
{
	t_stack	*aux;
	int		index;
	int		min;

	min = 0;
	index = -1;
	aux = a;
	while (aux)
	{
		if (index == -1)
		{
			min = aux->content;
			index = aux->index;
		}
		if (aux->content < min && (aux->index <= csize
				|| aux->index >= ft_stack_size(a) - csize - 1))
		{
			min = aux->content;
			index = aux->index;
		}
		aux = aux->next;
	}
	return (index);
}

int	get_index(t_stack *a, int num)
{
	t_stack	*aux;
	int		index;

	index = 0;
	aux = a;
	while (aux && aux->index != num)
	{
		aux = aux->next;
		index++;
	}
	return (index);
}

void	ft_order(t_stack **a, t_stack **b, int argc)
{
	if (argc < 4)
	{
		while (!is_ordered(*a))
			sort_3(a, 'a');
	}
	else if (argc <= 6)
	{
		if (!is_ordered(*a))
			sort_5(a, b);
	}
	else
	{
		if (!is_ordered(*a))
			sort_big(a, b, argc - 1);
	}
}
