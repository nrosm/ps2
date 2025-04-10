/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:07:04 by nroson-m          #+#    #+#             */
/*   Updated: 2025/04/10 13:07:04 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rev_rotate(t_list **stack)
{
	t_list	*start;
	t_list	*end;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	start = *stack;
	end = ft_lstlast(*stack);
	while (start)
	{
		if (start->next->next == NULL)
		{
			start->next = NULL;
			break ;
		}
		start = start->next;
	}
	end->next = *stack;
	*stack = end;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (rev_rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (rev_rotate(stack_b) == -1)
	{
		return (-1);
	}
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
