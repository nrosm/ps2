/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:24:52 by nroson-m          #+#    #+#             */
/*   Updated: 2024/10/04 12:57:47 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getnumdigits(int n)
{
	size_t	counter;
	int		temp;

	temp = n;
	counter = 0;
	if (n == 0)
		return (1);
	while (temp != 0)
	{
		temp /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char		*strinb;
	size_t		digits;
	long int	nb;

	nb = n;
	digits = ft_getnumdigits(n);
	if (n < 0)
	{
		nb *= -1;
		digits++;
	}
	strinb = (char *)malloc(sizeof(char) * (digits + 1));
	if (!strinb)
		return (NULL);
	strinb[digits] = '\0';
	while (digits--)
	{
		strinb[digits] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		strinb[0] = 45;
	return (strinb);
}
