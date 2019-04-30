/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimonis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:49:05 by tsimonis          #+#    #+#             */
/*   Updated: 2019/02/27 00:56:36 by tsimonis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	memalloc(char const *s, char c, char **result, size_t rows)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	t;

	result[0] = (char *)malloc(sizeof(*result) * 1);
	i = 0;
	k = 0;
	while (++i < rows)
	{
		j = k;
		while (s[j] == c)
			j++;
		k = j;
		while (s[k] != c && s[k])
			k++;
		result[i] = (char *)malloc(sizeof(*(result[i])) * (k - j + 1));
		if (!result[i])
			return (i);
		t = -1;
		while (++t < k - j)
			result[i][t] = s[j + t];
		result[i][t] = '\0';
	}
	return (i);
}

static int		find_rows(char const *s, char c, size_t *rows)
{
	size_t	i;
	int		fl;

	i = 0;
	fl = 0;
	while (s[i])
	{
		if (++(*rows) && s[i] == c && fl == 1)
			fl = 0;
		else if (--(*rows) + 1 && s[i] != c)
			fl = 1;
		if (*rows == (size_t)(-1))
			return (1);
		i++;
	}
	(*rows) += fl;
	if (*rows == (size_t)(-1))
		return (1);
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	rows;
	size_t	i;

	rows = 0;
	if (!s)
		return (NULL);
	else if (find_rows(s, c, &rows) == 1)
		return (NULL);
	rows++;
	if (rows == (size_t)(-1))
		return (NULL);
	result = (char **)malloc(sizeof(*result) * (rows + 1));
	if (!result)
		return (NULL);
	result[rows] = NULL;
	if ((i = memalloc(s, c, result, rows)) != rows)
	{
		rows = -1;
		while (++rows < i)
			free(result[rows]);
		free(result);
		result = NULL;
	}
	return (result);
}
