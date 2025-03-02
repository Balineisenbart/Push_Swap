/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:37:00 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:56:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cheapest	*find_cheapest_path_a(t_node **head_b, t_node **head_a,
		t_node **tail_a, t_node **tail_b)
{
	t_node		*candidate;
	t_cheapest	*arr;
	int			i;
	int			n;

	candidate = *head_b;
	i = 0;
	n = stack_length(*head_b);
	arr = malloc(n * sizeof(t_cheapest));
	if (!arr)
		return (free(arr), free_stack(head_a, tail_a), free_stack(head_b,
				tail_b), NULL);
	while (i < n)
	{
		arr[i] = set_arr(candidate, head_a, tail_a, i);
		i++;
		candidate = candidate->next;
	}
	return (arr);
}

t_cheapest	*find_cheapest_path_rev_a(t_node **head_b, t_node **head_a,
		t_node **tail_a, t_node **tail_b)
{
	t_node		*candidate;
	t_cheapest	*arr;
	int			i;
	int			n;

	candidate = *head_b;
	i = 0;
	n = stack_length(*head_b);
	arr = malloc(n * sizeof(t_cheapest));
	if (!arr)
		return (free(arr), free_stack(head_a, tail_a), free_stack(head_b,
				tail_b), NULL);
	while (i < n)
	{
		arr[i] = set_arr(candidate, head_a, tail_a, i);
		i++;
		candidate = candidate->prev;
	}
	return (arr);
}

void	finish(t_node **head_a, t_node **tail_a, t_node **head_b,
		t_node **tail_b)
{
	t_cheapest	cost;

	if (!(*head_a) || !(*head_b))
		return ;
	while (*head_b)
	{
		cost = return_cheapest_arr(head_b, head_a, tail_a, tail_b);
		if (cost.move == RX && cost.dir == RB)
			rx_rb(head_a, tail_a, head_b, tail_b);
		else if (cost.move == RRX && cost.dir == RB)
			rrx_rb(head_a, tail_a, head_b, tail_b);
		else if (cost.move == RRX && cost.dir == RRB)
			rrx_rrb(head_a, tail_a, head_b, tail_b);
		else
			rx_rrb(head_a, tail_a, head_b, tail_b);
		pa(head_a, tail_a, head_b, tail_b);
	}
}
