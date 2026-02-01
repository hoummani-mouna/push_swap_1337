#include "push_swap.h"
static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;
	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}
void	pa(t_stack **a, t_stack **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pa\n", 3);
}
void	pb(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pb\n", 3);
}
