#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct  s_node
{
    int value;
    struct s_node *next;
}   t_node;

typedef struct  s_stack
{
    t_node  *top;
    int     size;
}   t_stack;

void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack	*a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

int     is_valid_number(char *str);
void    check_duplicates(int argc, char *argv[]);
void	add_to_stack(t_stack *stack,long num);

//helper func
long    ft_atol(const char *nptr);

//sort functions
void	sort_two(t_stack *a);
void	sort_three(t_stack *a);

#endif