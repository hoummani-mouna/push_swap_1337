#include "push_swap.h"
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
static int	get_target(t_stack **a, int b_idx, int target_idx, int target_val)
{
	t_stack	*tmp_a;
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_val)
		{
			target_val = tmp_a->index;
			target_idx = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_val != INT_MAX)
		return (target_idx);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_val)
		{
			target_val = tmp_a->index;
			target_idx = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_idx);
}
void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;
	get_position(a);
	get_position(b);
	tmp_b = *b;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b->index, INT_MAX, INT_MAX);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
