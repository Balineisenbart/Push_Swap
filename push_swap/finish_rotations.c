/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_rotations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:13:46 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:58:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx_rb(t_node **head_a, t_node **tail_a, t_node **head_b,
		t_node **tail_b)
{
	t_cheapest	cost;

	cost = return_cheapest_arr(head_b, head_a, tail_a, tail_b);
	if (cost.iterations >= cost.other_r)
	{
		while (cost.other_r-- > 0)
		{
			rr(head_a, tail_a, head_b, tail_b);
			cost.iterations--;
		}
		while (cost.iterations-- > 0)
			ra(head_a, tail_a, 's');
	}
	if (cost.other_r > cost.iterations)
	{
		while (cost.iterations-- > 0)
		{
			rr(head_a, tail_a, head_b, tail_b);
			cost.other_r--;
		}
		while (cost.other_r-- > 0)
			rb(head_b, tail_b, 's');
	}
}

void	rrx_rrb(t_node **head_a, t_node **tail_a, t_node **head_b,
		t_node **tail_b)
{
	t_cheapest	cost;

	cost = return_cheapest_arr(head_b, head_a, tail_a, tail_b);
	if (cost.iterations >= cost.other_r)
	{
		while (cost.other_r-- > 0)
		{
			rrr(head_a, tail_a, head_b, tail_b);
			cost.iterations--;
		}
		while (cost.iterations-- > 0)
			rra(head_a, tail_a, 's');
	}
	if (cost.other_r > cost.iterations)
	{
		while (cost.iterations-- > 0)
		{
			rrr(head_a, tail_a, head_b, tail_b);
			cost.other_r--;
		}
		while (cost.other_r-- > 0)
			rrb(head_b, tail_b, 's');
	}
}

void	rrx_rb(t_node **head_a, t_node **tail_a, t_node **head_b,
		t_node **tail_b)
{
	t_cheapest	cost;

	cost = return_cheapest_arr(head_b, head_a, tail_a, tail_b);
	while (cost.iterations-- > 0)
		rra(head_a, tail_a, 's');
	while (cost.other_r-- > 0)
		rb(head_b, tail_b, 's');
}

void	rx_rrb(t_node **head_a, t_node **tail_a, t_node **head_b,
		t_node **tail_b)
{
	t_cheapest	cost;

	cost = return_cheapest_arr(head_b, head_a, tail_a, tail_b);
	while (cost.iterations-- > 0)
		ra(head_a, tail_a, 's');
	while (cost.other_r-- > 0)
		rrb(head_b, tail_b, 's');
}
