#include "../../include/push_swap.h"

static void	rotate_both_stacks(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node,
								bool reverse)
								{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
	{
		if (reverse)
			rrr(a, b, false);
		else
			rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	throw_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both_stacks(a, b, cheapest_node, false);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rotate_both_stacks(a, b, cheapest_node, true);
	ready_for_push(a, cheapest_node, 'a');
	ready_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

static void	throw_b_to_a(t_stack_node **a, t_stack_node **b)
{
	ready_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	smallest_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		throw_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		throw_b_to_a(a, b);
	}
	current_index(*a);
	smallest_on_top(a);
}
