#include "../push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	if (tmp->value > tmp->next->value && tmp->value < tmp->next->next->value)
		sa(a);
	else if(tmp->value < tmp->next->value && tmp->value > tmp->next->next->value)
		rra(a);
	else if(tmp->value > tmp->next->value && tmp->next->value > tmp->next->next->value)
	{
		sa(a);
		rra(a);
	}
	else if(tmp->value > tmp->next->value && tmp->next->value < tmp->next->next->value)
		ra(a);
	else if(tmp->value < tmp->next->value && tmp->next->value > tmp->next->next->value)
	{
		sa(a);
		ra(a);
	}
}