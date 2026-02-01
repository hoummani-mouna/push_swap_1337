#include "push_swap.h"
void	get_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;
	tmp_b = *b;
	size_a = ft_stack_size(*a);
	size_b = ft_stack_size(*b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}
static int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
static void	do_rev_rotate_both(t_stack **a, t_stack **b,
									int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b, 1);
	}
}
static void	do_rotate_both(t_stack **a, t_stack **b,
								int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b, 1);
	}
}
static void	do_rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a, 1);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a, 1);
		(*cost_a)++;
	}
}
static void	do_rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b, 1);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b, 1);
		(*cost_b)++;
	}
}
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(a, b, &cost_a, &cost_b);
	do_rotate_a(a, &cost_a);
	do_rotate_b(b, &cost_b);
	pa(a, b, 1);
}
void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
