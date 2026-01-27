#include "push_swap.h"

t_node get_last(t_stack *x)
{
    while(x->top->next)
        top = x->top->next;
    return top;
}
