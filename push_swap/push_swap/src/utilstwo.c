#include "../include/push_swap.h"

void ft_puterror(char *msg)
{
    ft_putendl_fd(msg, 1);
    exit(0);
}
void free_strings(char **s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    while (i >= 0)
        free (s[i--]);
}

int sort_verif(t_list **stack)
{
    t_list *start;

    start = *stack;

    while(start && start->next)
    {
        if (start->value > start->next->value)
            return (0);
        start = start->next;
    }
    return (1);
}

int get_dist(t_list **stack, int index)
{
    t_list *start;
    int i;

    start = *stack;
    i = 0;
    while (start)
    {
        if (start->index == index)
            return (i);
        i++;
        start = start->next;
    }
    return (i);
}

void    movetotop(t_list **stack, int dist)
{
    t_list *start;
    int tmp;

    if (dist == 0)
        return ;

    start = *stack;
    tmp = ft_lstsize(start) - dist;

    if (dist <= (ft_lstsize(start) / 2))
    {
        while (dist-- > 0)
            ra(stack);
    }
    else
    {
        while (tmp-- > 0)
            rra(stack);
    }
}

void free_stack(t_list **stack)
{
    t_list *start;
    t_list *tmp;

    start = *stack;

    while (start)
    {
        tmp = start;
        start = start->next;
        free(tmp);
    }
    free(stack);
}
