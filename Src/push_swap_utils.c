/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 19:17:28 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/13 19:57:23 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../Inc/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*aux_st;

	aux_st = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!aux_st)
		return (NULL);
	aux_st->content = content;
	aux_st->index = 0;
	aux_st->next = NULL;
	return (aux_st);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

void	ft_free(t_stack **stack)
{
	t_stack	*aux;

	while (*stack)
	{
		aux = *stack;
		*stack = (*stack)->next;
		free(aux);
	}
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	if (new)
	{
		if (!*stack)
			*stack = new;
		else
			ft_stacklast(*stack)->next = new;
	}
}

void	assign_index(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*aux2;
	int		ind;

	ind = 0;
	aux2 = *stack;
	aux = *stack;
	while (aux)
	{
		while (aux2)
		{
			if (aux2->content != aux->content && aux2->content <= aux->content)
				ind++;
			aux2 = aux2->next;
		}
		aux->index = ind;
		ind = 0;
		aux = aux->next;
		aux2 = *stack;
	}
}
