/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:31:25 by nroson-m          #+#    #+#             */
/*   Updated: 2024/10/04 13:25:40 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		buffer;
	size_t		i;
	char		*ptr;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	buffer = (ft_strlen(s1) + ft_strlen(s2) + 1);
	ptr = malloc(buffer);
	if (ptr == NULL)
		return (NULL);
	while (*s1)
		*(ptr + i++) = *s1++;
	while (*s2)
		*(ptr + i++) = *s2++;
	*(ptr + i) = '\0';
	return (ptr);
}
