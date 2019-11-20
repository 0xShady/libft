/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:42:17 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/10/22 00:21:28 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(const char *str, char c)
{
	int count;
	int words;
	int test;

	test = 0;
	count = 0;
	words = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
		{
			test = 1;
			words = 0;
		}
		else if (words == 0)
		{
			words = 1;
			count++;
		}
		str++;
	}
	return ((test == 0 && count == 1) ? -1 : count);
}

static int		words_lenght(const char *str, int i, char c)
{
	int lenght;

	lenght = 0;
	while (str[i] != c && str[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static void		ft_free(char **tab, int j)
{
	while (j <= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
}

static char		**help(const char *str)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (!(tab = (char**)malloc(sizeof(char*) * 2)))
		return (NULL);
	if (!(tab[0] = (char*)malloc(1 * ft_strlen(str) + 1)))
		ft_free(tab, j);
	while (str[i])
	{
		tab[0][i] = str[i];
		i++;
	}
	tab[0][i] = '\0';
	tab[1] = NULL;
	return (tab);
}

char			**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;
	int		k;
	int		j;

	i = 0;
	j = 0;
	if (count_words(str, c) == -1 || !str)
		return ((count_words(str, c) == -1) ? help(str) : NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (count_words(str, c) + 1))))
		return (NULL);
	while (str[i] != '\0' && j < count_words(str, c))
	{
		k = 0;
		while (str[i] == c)
			i++;
		if (!(tab[j] = (char*)malloc(1 * words_lenght(str, i, c) + 1)))
			ft_free(tab, j);
		while (str[i] != c && str[i] != '\0')
			tab[j][k++] = str[i++];
		tab[j++][k] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}
