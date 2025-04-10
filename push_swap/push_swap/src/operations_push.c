/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:07:07 by nroson-m          #+#    #+#             */
/*   Updated: 2025/04/10 13:07:07 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push(t_list **stack_dest, t_list **stack_orig)
{
	t_list	*tmp;
	t_list	*start_dest;
	t_list	*start_orig;

	if (ft_lstsize(*stack_orig) == 0)
		return (-1);
	start_dest = *stack_dest;
	start_orig = *stack_orig;
	tmp = start_orig;
	start_orig = start_orig->next;
	*stack_orig = start_orig;
	if (!start_dest)
	{
		start_dest = tmp;
		start_dest->next = NULL;
		*stack_dest = start_dest;
	}
	else
	{
		tmp->next = start_dest;
		*stack_dest = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
