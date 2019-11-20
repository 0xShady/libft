/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 23:10:30 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/10/21 04:34:38 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	if (n == 0)
	{
		return (0);
	}
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while (a[i] == b[i] && (a[i] != '\0' || b[i] != '\0') && i < n - 1)
		i++;
	return (a[i] - b[i]);
}
