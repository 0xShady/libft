/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:52:34 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/10/21 04:34:39 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	if (!(result = malloc(size * count)))
		return (0);
	while (i < count * size)
	{
		result[i++] = 0;
	}
	return (result);
}
