#include "push_swap.h"
#include <unistd.h>
t_stack	*ft_stack_new(int value)
{
	t_stack	*new;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}
void	ft_stack_add_back( t_stack **stack, t_stack *new_node)
{
	t_stack	*curr;
	if (!new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}
t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
int	ft_stack_size(t_stack *stack)
{
	int	len;
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}
void	ft_error(t_stack **a, t_stack **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}
