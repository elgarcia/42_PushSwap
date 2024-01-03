/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:52:09 by eliagarc          #+#    #+#             */
/*   Updated: 2023/11/16 17:34:05 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Inc/push_swap.h"
#include "../libft/libft.h"

static int	already_exists(t_stack **stack, int nbr)
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

static int	is_nbrvalid(char *s)
{
	int		i;
	long	j;

	i = 0;
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
	if (!ft_isdigit(s[i - 1]))
		return (-1);
	return (i);
}

static int	init_stack(t_stack **stack, int size, char **argv)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (is_nbrvalid(argv[i]) != -1 && argv[i][0]
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
	assign_index(stack);
	return (0);
}

/* static void	ft_show(t_stack *a)
{
	t_stack	*aux;

	aux = a;
	printf("----------STACK-------\n");
	while (aux)
	{
		printf("%d\n", aux->content);
		aux = aux->next;
	}
} */

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 0)
	{
		if (init_stack(&a, argc, argv) == -1)
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_order(&a, &b, argc);
	}
	ft_free(&a);
	return (0);
}
