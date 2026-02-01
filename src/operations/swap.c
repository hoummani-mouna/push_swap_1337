#include "push_swap.h"
static void	swap(t_stack *stack)
{
	int	tmp;
	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}
void	sa(t_stack **a, int print)
{
	swap(*a);
	if (print)
		write(1, "sa\n", 3);
}
void	sb(t_stack **b, int print)
{
	swap(*b);
	if (print)
		write(1, "sb\n", 3);
}
void	ss(t_stack **a, t_stack **b, int print)
{
	swap(*a);
	swap(*b);
	if (print)
		write(1, "ss\n", 3);
}
