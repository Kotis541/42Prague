#include "push_swap.h"

void	sa(t_stack *a)
{
    int	tmp;

    tmp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = tmp;
    write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
    int	tmp;

    tmp = b->top->value;
    b->top->value = b->top->next->value;
    b->top->next->value = tmp;
    write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
    t_node	*tmp;

	if (b->size == 0)
		return ;
	tmp = b->top;
	b->top = b->top->next;
	tmp->next = a->top;
	a->top = tmp;
	a->size++;
	b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	if (a->size == 0)
		return ;
	tmp = a->top;
	a->top = a->top->next;
	tmp->next = b->top;
	b->top = tmp;
	b->size++;
	a->size--;
	write(1, "pb\n", 3);
}

void ra(t_stack *a)
{
	int i;

	i = 0;
	get_last(a);
}