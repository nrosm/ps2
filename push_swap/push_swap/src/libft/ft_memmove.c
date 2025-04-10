/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:19:08 by nroson-m          #+#    #+#             */
/*   Updated: 2024/10/04 13:26:20 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*temp;
	size_t				i;

	if (!dest && !src && n > 0)
		return (NULL);
	temp = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (src < dest)
	{
		while (n-- > 0)
			d[n] = temp[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = temp[i];
			i++;
		}
	}
	return (dest);
}
