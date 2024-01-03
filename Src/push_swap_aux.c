/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:18:37 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/15 21:18:56 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"
#include "../libft/libft.h"

int	already_exists(t_stack **stack, int nbr)
{
	t_stack	*aux;

	aux = *stack;
	while (aux)
	{
		if (nbr == aux->content)
			return (-1);
		aux = aux->next;
	}
	aux = ft_stacklast(*stack);
	aux->next = ft_stacknew(nbr);
	if (aux->next == NULL)
	{
		ft_free(stack);
		return (-1);
	}
	return (0);
}

int	is_nbrvalid(char *s)
{
	int		i;
	long	j;

	i = 0;
	if (!s[0])
		return (-1);
	j = ft_atoi(s);
	if (j < INT_MIN || j > INT_MAX)
		return (-1);
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != '-')
			return (-1);
		if (i != 0 && s[i] == '-')
			return (-1);
		i++;
	}
	return (i);
}

int	init_stack(t_stack **stack, int size, char **argv)
{
	int		i;

	i = 1;
	while (i < size)
	{
		if (is_nbrvalid(argv[i]) != -1
			&& ((ft_atoi(argv[i]) >= INT_MIN) && (ft_atoi(argv[i]) <= INT_MAX)))
		{
			if (!(*stack))
			{
				*stack = ft_stacknew(ft_atoi(argv[i]));
				if (!*stack)
					return (-1);
			}
			else if (already_exists(stack, ft_atoi(argv[i])) == -1)
				return (-1);
		}
		else
			return (-1);
		i++;
	}
	return (0);
}

int	ft_stack_size(t_stack *a)
{
	t_stack	*aux;
	int		i;

	i = 0;
	aux = a;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	ft_order_rr(t_stack **a)
{
	if (get_index(*a, 0) > ft_stack_size(*a))
	{
		while (!is_ordered(*a))
			ft_reverse(a, 'a');
	}
	else
		while (!is_ordered(*a))
			ft_rotate(a, 'a');
}
