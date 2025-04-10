/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:07:51 by nroson-m          #+#    #+#             */
/*   Updated: 2025/04/10 13:07:51 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	min_value(t_list **stack, int value)
{
	t_list	*start;
	int		min;

	start = *stack;
	min = start->index;
	while (start->next)
	{
		start = start->next;
		if ((start->index < min) && start->index != value)
			min = start->index;
	}
	return (min);
}

void	printlist(t_list *start)
{
	t_list	*tmp;

	tmp = start;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

static t_list	*getmin(t_list **stack)
{
	t_list	*min;
	t_list	*start;
	int		alrmin;

	start = *stack;
	min = NULL;
	alrmin = 0;
	if (start)
	{
		while (start)
		{
			if ((start->index == -1) && ((!alrmin)
					|| (start->value < min->value)))
			{
				min = start;
				alrmin = 1;
			}
			start = start->next;
		}
	}
	return (min);
}

void	indexes(t_list **stack)
{
	t_list	*start;
	int		index;

	index = 0;
	start = getmin(stack);
	while (start)
	{
		start->index = index++;
		start = getmin(stack);
	}
}
