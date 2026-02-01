#include "push_swap.h"
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;
	if (!*stack || !(*stack)->next)
		return ;
	tail = ft_stack_last(*stack);
	before_tail = *stack;
	while (before_tail->next && before_tail->next != tail)
		before_tail = before_tail->next;
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}
void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}
void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}
void	rrr(t_stack **a, t_stack **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
