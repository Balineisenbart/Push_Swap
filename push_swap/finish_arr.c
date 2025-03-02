/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:20:48 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:25:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_rx(t_node *candidate, t_node **head_a, int total_len)
{
	t_node	*current;
	int		count_rx;

	current = *head_a;
	count_rx = 0;
	while (!(candidate->index == current->index - 1
			|| ((candidate->index == total_len - 1) && current->index == 0))
		&& count_rx < stack_length(*head_a))
	{
		current = current->next;
		count_rx++;
		if (count_rx == stack_length(*head_a))
			count_rx = INT_MAX;
	}
	return (count_rx);
}

static int	ft_count_rrx(t_node *candidate, t_node **head_a, t_node **tail_a,
		int total_len)
{
	t_node	*current;
	t_node	*current_tail;
	int		count_rrx;

	current = *head_a;
	current_tail = *tail_a;
	count_rrx = 0;
	while (!(candidate->index == current->index - 1
			|| ((candidate->index == total_len - 1) && current->index == 0))
		&& count_rrx < stack_length(*head_a))
	{
		current = current_tail;
		current_tail = current_tail->prev;
		count_rrx++;
		if (count_rrx == stack_length(*head_a))
			count_rrx = INT_MAX;
	}
	return (count_rrx);
}

static t_cheapest	set_rotation(int count, int i, int move)
{
	t_cheapest	rotation;

	rotation.move = move;
	rotation.iterations = count;
	rotation.other_r = i;
	rotation.price = INT_MAX;
	return (rotation);
}

t_cheapest	set_arr(t_node *candidate, t_node **head_a, t_node **tail_a, int i)
{
	int	count_rx;
	int	count_rrx;
	int	total_len;

	total_len = stack_length(candidate) + stack_length(head_a);
	count_rx = ft_count_rx(candidate, head_a, total_len);
	count_rrx = ft_count_rrx(candidate, head_a, tail_a, total_len);
	if (count_rx <= count_rrx)
		return (set_rotation(count_rx, i, RX));
	else
		return (set_rotation(count_rrx, i, RRX));
}
