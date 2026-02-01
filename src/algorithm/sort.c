#include "push_swap.h"
static void	assign_index(t_stack *stack_a)
{
	t_stack	*ptr;
	t_stack	*target;
	int		matches;
	ptr = stack_a;
	while (ptr)
	{
		matches = 0;
		target = stack_a;
		while (target)
		{
			if (target->value < ptr->value)
				matches++;
			target = target->next;
		}
		ptr->index = matches + 1;
		ptr = ptr->next;
	}
}
void	sort_three(t_stack **a)
{
	t_stack	*head;
	int		max_index;
	head = *a;
	if (head->index > head->next->index && head->index > head->next->next->index)
		max_index = head->index;
	else if (head->next->index > head->index && head->next->index > head->next->next->index)
		max_index = head->next->index;
	else
		max_index = head->next->next->index;
	if ((*a)->index == max_index)
		ra(a, 1);
	else if ((*a)->next->index == max_index)
		rra(a, 1);
	if ((*a)->index > (*a)->next->index)
		sa(a, 1);
}
static void	push_all_save_three(t_stack **a, t_stack **b, int stack_size)
{
	int	pushed;
	int	i;
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a)->index <= stack_size / 2)
		{
			pb(a, b, 1);
			pushed++;
		}
		else
			ra(a, 1);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(a, b, 1);
		pushed++;
	}
}
static void	shift_stack(t_stack **a)
{
	int		lowest_pos;
	int		size;
	t_stack	*tmp;
	int		i;
	size = ft_stack_size(*a);
	lowest_pos = 0;
	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->index == 1)
			lowest_pos = i;
		tmp = tmp->next;
		i++;
	}
	if (lowest_pos > size / 2)
	{
		while ((*a)->index != 1)
			rra(a, 1);
	}
	else
	{
		while ((*a)->index != 1)
			ra(a, 1);
	}
}
void	sort_stack(t_stack **a, t_stack **b)
{
	int	stack_size;
	stack_size = ft_stack_size(*a);
	assign_index(*a);
	if (stack_size == 2)
		sa(a, 1);
	else
	{
		push_all_save_three(a, b, stack_size);
		sort_three(a);
		while (*b)
		{
			get_target_position(a, b);  
			get_cost(a, b);             
			do_cheapest_move(a, b);     
		}
		shift_stack(a);
	}
}
