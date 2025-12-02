#include "../../include/push_swap.h"

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static char	**parse_args(int argc, char **argv, int *is_split)
{
	char	**args;

	*is_split = 0;
	if (argc == 2)
	{
		args = split(argv[1], ' ');
		*is_split = 1;
	}
	else
		args = argv + 1;
	return (args);
}

static void	sort_dispatch(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

static void	handle_pushswap(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				is_split;

	a = NULL;
	b = NULL;
	args = parse_args(argc, argv, &is_split);
	init_stack_a(&a, args, is_split);
	if (!stack_sorted(a))
		sort_dispatch(&a, &b);
	free_stack(&a);
	if (is_split)
		free_split(args);
}

int	main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	handle_pushswap(argc, argv);
	return (0);
}
