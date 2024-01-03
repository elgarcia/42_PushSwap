/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:09:30 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/15 21:17:13 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"

void	reduce_stack(t_stack **a, t_stack **b, int size)
{
	int	nc_aux;
	int	nc;
	int	aux;
	int	limit_aux;

	nc = 0;
	aux = 0;
	nc_aux = size / 5;
	if (size >= 500)
		nc_aux = size / 6;
	limit_aux = nc_aux;
	while (*a)
	{
		while (*a && aux < limit_aux)
		{
			search_min(a, 'a', limit_aux, &nc);
			ft_push(a, b, 'b');
			if ((*b)->index < (limit_aux - nc) / 2 + nc)
				ft_rotate(b, 'b');
			aux++;
		}
		limit_aux += nc_aux;
		nc += nc_aux;
	}
}

int	is_min(t_stack **a, int num)
{
	t_stack	*aux;

	aux = *a;
	while (aux && (aux->content == num || aux->content > num))
	{
		aux = aux->next;
	}
	if (aux)
		return (1);
	else
		return (0);
}

int	is_max(t_stack **a, int num)
{
	t_stack	*aux;

	aux = *a;
	while (aux && (aux->content == num || aux->content < num))
		aux = aux->next;
	if (aux)
		return (1);
	else
		return (0);
}

void	clean_b(t_stack **a, t_stack **b, int size)
{
	int	nc_aux;
	int	nc;
	int	limit_aux;

	nc = size - 1;
	nc_aux = size / 5;
	if (size >= 500)
		nc_aux = size / 6;
	limit_aux = size - nc_aux;
	while (*b)
	{
		while (*b && nc >= limit_aux)
		{
			search_max(b, 'b', &nc);
			ft_push(b, a, 'a');
		}
		limit_aux -= nc_aux;
	}
	ft_free(b);
}

void	clean_b_5(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if (ft_stack_size(*a) == 3)
			sort_4(a, b);
		else
			sort_4in5(a, b);
	}
	ft_order_rr(a);
}
