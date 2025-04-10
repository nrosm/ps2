/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:15:35 by nroson-m          #+#    #+#             */
/*   Updated: 2024/10/01 11:40:38 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*str;

	bytes = nmemb * size;
	if (size && (bytes / size) != nmemb)
		return (NULL);
	str = malloc(bytes);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, bytes);
	return (str);
}
