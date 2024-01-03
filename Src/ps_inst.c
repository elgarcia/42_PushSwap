/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:19:17 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/08 12:16:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"
#include "../libft/libft.h"

void	ft_swap(t_stack **ab, char stack)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*ab && (*ab)->next)
	{
		aux = (*ab);
		aux2 = (*ab)->next;
		aux->next = aux2->next;
		aux2->next = aux;
		*ab = aux2;
	}
	ft_printf("s%c\n", stack);
}

void	ft_swap_swap(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux2_a;
	t_stack	*aux_b;
	t_stack	*aux2_b;

	if ((*a && *b) && ((*a)->next && (*b)->next))
	{
		aux_a = *a;
		aux2_a = (*a)->next;
		aux_b = *b;
		aux2_b = (*b)->next;
		aux_a->next = aux2_a->next;
		aux_b->next = aux2_b->next;
		aux2_a->next = aux_a;
		aux2_a->next = aux_b;
		*a = aux2_a;
		*b = aux2_b;
	}
	ft_printf("ss\n");
}

void	ft_push(t_stack **a, t_stack **b, char stack)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*a)
	{
		aux = *a;
		aux2 = (*a)->next;
		aux->next = *b;
		*b = aux;
		*a = aux2;
	}
	ft_printf("p%c\n", stack);
}

void	ft_reverse(t_stack **a, char stack)
{
	t_stack	*aux;
	t_stack	*aux2;

	if (*a && (*a)->next)
	{
		aux = *a;
		aux2 = *a;
		while (aux2->next->next)
			aux2 = aux2->next;
		aux2->next->next = aux;
		aux = aux2->next;
		aux2->next = NULL;
		*a = aux;
	}
	ft_printf("rr%c\n", stack);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	t_stack	*aux_a;
	t_stack	*aux2_a;
	t_stack	*aux_b;
	t_stack	*aux2_b;

	if ((*a && *b) && ((*a)->next && (*b)->next))
	{
		aux_a = *a;
		aux_b = *b;
		aux2_a = *a;
		aux2_b = *b;
		while (aux2_a->next->next)
			aux2_a = aux2_a->next;
		while (aux2_b->next->next)
			aux2_b = aux2_b->next;
		aux2_a->next->next = aux_a;
		aux2_b->next->next = aux_b;
		aux_a = aux2_a->next;
		aux_b = aux2_b->next;
		aux2_a->next = NULL;
		aux2_b->next = NULL;
		*a = aux_a;
		*b = aux_b;
	}
	ft_printf("rrr\n");
}
