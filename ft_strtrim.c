/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 03:37:17 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/10/22 00:29:13 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		test(char a, const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (a == s[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static	int		fstart(const char *s1, const char *s2)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		if (test(s1[i], s2) != 1)
			return (i);
		i++;
	}
	return (0);
}

static	int		fend(const char *s1, const char *s2)
{
	int	l;

	l = 0;
	while (s1[l] != '\0')
	{
		l++;
	}
	l -= 1;
	while (l > 0)
	{
		if (test(s1[l], s2) != 1)
			return (l);
		l--;
	}
	return (0);
}

static	char	*substring(char const *s, unsigned int start, size_t len)
{
	int		k;
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = len + start;
	k = start;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[start] != '\0' && k < j)
	{
		tab[i] = s[start];
		i++;
		start++;
		k++;
	}
	tab[i] = '\0';
	return (tab);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		help;
	char	*tab;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	start = fstart(s1, set);
	help = start;
	end = (fend(s1, set) - help);
	if (end == 0)
	{
		if (!(tab = (char *)malloc(1 * sizeof(char))))
			return (0);
		tab[0] = '\0';
		return (tab);
	}
	end += 1;
	return (substring(s1, start, end));
}
