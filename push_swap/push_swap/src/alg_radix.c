/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:06:50 by nroson-m          #+#    #+#             */
/*   Updated: 2025/04/10 13:06:50 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_max_bits(t_list **stack)
{
	t_list	*start;
	int		max;
	int		max_bits;

	start = *stack;
	max = start->index;
	max_bits = 0;
	while (start)
	{
		if (start->index > max)
			max = start->index;
		start = start->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b, int max_bits, int size)
{
	int		i;
	int		j;
	t_list	*start_a;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			start_a = *stack_a;
			if (((start_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}

void	ft_sorting(t_list **stack_a, t_list **stack_b)
{
	t_list	*start_a;
	int		max_bits;
	int		size;

	start_a = *stack_a;
	size = ft_lstsize(start_a);
	max_bits = ft_max_bits(stack_a);
	ft_radix_sort(stack_a, stack_b, max_bits, size);
}

