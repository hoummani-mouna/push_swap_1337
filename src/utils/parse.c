#include "push_swap.h"
static int	is_number(char *str)
{
	int	i;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
static void	msg_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
static void	check_duplicate(t_stack *a, int n)
{
	if (!a)
		return ;
	while (a)
	{
		if (a->value == n)
			msg_error();
		a = a->next;
	}
}
static void	process_arg(t_stack **a, char **args)
{
	long	n;
	int		j;
	j = 0;
	while (args[j])
	{
		if (is_number(args[j]))
		{
			n = ft_atol(args[j]);
			if (n > INT_MAX || n < INT_MIN)
				msg_error();
			check_duplicate(*a, (int)n);
			ft_stack_add_back(a, ft_stack_new((int)n));
		}
		else
			msg_error();
		free(args[j]);
		j++;
	}
	free(args);
}
t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	char	**args;
	a = NULL;
	i = 1;
	if (argc < 2)
		return (NULL);
	if (argc == 2 && !argv[1][0])
		msg_error();
	while (i < argc)
	{
		args = ft_split(argv[i], ' ');
		if (!args)
			msg_error();
		process_arg(&a, args);
		i++;
	}
	return (a);
}
