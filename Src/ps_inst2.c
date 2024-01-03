/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:23:05 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/13 19:55:28 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"
#include "../libft/libft.h"

void	ft_rotate(t_stack **a, char stack)
{
	t_stack	*aux;
	t_stack	*aux2;
	t_stack	*aux3;

	aux = *a;
	aux2 = *a;
	aux3 = (*a)->next;
	if (*a && (*a)->next)
	{
		while (aux2->next->next)
			aux2 = aux2->next;
		aux2->next->next = aux;
		aux->next = NULL;
		*a = aux3;
	}
	ft_printf("r%c\n", stack);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	t_stack	*aux2;
	t_stack	*aux3;

	aux = *a;
	aux2 = *a;
	aux3 = (*a)->next;
	if ((*a && (*a)->next) && (*b && (*b)->next))
	{
		while (aux2->next->next)
			aux2 = aux2->next;
		aux2->next->next = aux;
		aux->next = NULL;
		*a = aux3;
		aux = *b;
		aux2 = *b;
		aux3 = (*b)->next;
		while (aux2->next->next)
			aux2 = aux2->next;
		aux2->next->next = aux;
		aux->next = NULL;
		*b = aux3;
	}
	ft_printf("rr\n");
}

int	is_ordered(t_stack *a)
{
	t_stack	*aux;
	int		control;

	aux = a;
	control = 1;
	while ((aux && aux->next) && control)
	{
		if (aux->content < aux->next->content)
			aux = aux->next;
		else
			control = 0;
	}
	return (control);
}

void	search_min(t_stack **a, char stack, int csize, int *cini)
{
	int	index;
	int	mid;

	mid = ft_stack_size(*a) / 2;
	index = get_index(*a, *cini);
	if (index > mid)
	{
		while ((*a)->index > csize)
			ft_reverse(a, stack);
	}
	else
	{
		while ((*a)->index > csize)
			ft_rotate(a, stack);
	}
	if ((*a)->index == *cini)
		(*cini)++;
}

void	search_max(t_stack **a, char stack, int *cini)
{
	int	index;
	int	mid;
	int	al;

	mid = ft_stack_size(*a) / 2;
	index = get_max(*a);
	al = get_index(*a, index);
	if (al > mid)
	{
		while ((*a)->index != index)
			ft_reverse(a, stack);
	}
	else
	{
		while ((*a)->index != index)
			ft_rotate(a, stack);
	}
	if ((*a)->index == index)
		(*cini)--;
}
