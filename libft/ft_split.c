/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliagarc <eliagarc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:44:42 by eliagarc          #+#    #+#             */
/*   Updated: 2023/09/15 13:44:43 by eliagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s1, char delimiter)
{
	int	counter;
	int	aux;

	aux = 0;
	counter = 0;
	if (!s1)
		return (0);
	while (*s1)
	{
		while (*s1 == delimiter && *s1)
		{
			s1++;
			aux = 1;
		}
		while (*s1 != delimiter && *s1)
		{
			s1++;
			aux = 2;
		}
		if (aux == 2)
			counter++;
	}
	return (counter);
}

static char	*move_str(char *s1, char c, int	*index)
{
	int	i;

	i = *index;
	while (*s1 == c && *s1)
		s1++;
	while (s1[i] != c && s1[i])
		i++;
	*index = i;
	return (s1);
}

static void	free_split(char **sp, int sp_size)
{
	while (sp_size-- > 0)
	{
		free(sp[sp_size]);
	}
	free(sp);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	*aux;
	char	**aux_matrix;

	i = 0;
	j = 0;
	aux = (char *)s;
	aux_matrix = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!aux_matrix)
		return (NULL);
	while (j < word_count(s, c))
	{
		aux = move_str(aux, c, &i);
		aux_matrix[j] = ft_substr(aux, 0, i);
		if (!aux_matrix[j++])
		{
			free_split(aux_matrix, j);
			return (NULL);
		}
		aux += i;
		i = 0;
	}
	aux_matrix[j] = 0;
	return (aux_matrix);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	char * * tab = ft_split(((void *)0), 'z');
	//char * splitme = strdup("Tripouille");
	//printf("SDwq\n");
	// tab = ft_split(splitme, ' ');
	if (!(tab = ft_split(((void *)0), 'z')))
        printf("NULL");
    else
        if (!tab[0])
            printf("ok\n");
	// printf("Test normal case:\n");
	int i;
	for (i = 0; tab[i]; i++)
		printf("String %d : %s\n", i, tab[i]);
	printf("String %d : %s\n", i, tab[i]);
} */