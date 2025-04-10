
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/libft.h"


typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;


t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *start);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);
int		min_value(t_list **stack, int value);

void	ft_puterror(char *msg);
void	checkargs(int argc, char **argv);
int		sort_verif(t_list **stack);
int		get_dist(t_list **stack, int index);
void    movetotop(t_list **stack, int dist);
void	free_stack(t_list **stack);
void	free_strings(char **s);



void	ft_sorting(t_list **stack_a, t_list **stack_b);
void	short_sort (t_list **stack_a, t_list **stack_b);
void	indexes(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);


int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		rev_rotate(t_list **stack);

int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif
