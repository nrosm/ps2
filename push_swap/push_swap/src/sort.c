/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nroson-m <nroson-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:07:23 by nroson-m          #+#    #+#             */
/*   Updated: 2025/04/10 13:07:23 by nroson-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



static void	handle(t_list **stack_a, t_list *start, int min, int next_min)
{
	if (start->index == min && start->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (start->index == next_min)
	{
		if (start->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (start->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

static void	sort_three(t_list **stack_a)
{
	t_list	*start;
	int		min;
	int		next_min;

	start = *stack_a;
	min = min_value(stack_a, -1);
	next_min = min_value(stack_a, min);
	if (sort_verif(stack_a))
		return;
	handle(stack_a, start, min, next_min);
}



static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	dist = get_dist(stack_a, min_value(stack_a, -1));
	if (sort_verif(stack_a))
		return ;
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
		rra(stack_a);
	if (sort_verif(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	dist = get_dist(stack_a, min_value(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (dist == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	if (dist == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	short_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (sort_verif(stack_a) || size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
