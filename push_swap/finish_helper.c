/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:16:48 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:25:43 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cheapest	find_cheapest_arr(t_cheapest *arr, t_node **head)
{
	t_cheapest	smallest;
	int			size;
	int			i;

	size = stack_length(*head);
	i = 0;
	while (i < size)
	{
		arr[i] = price_calc(arr[i]);
		i++;
	}
	i = 0;
	smallest = arr[0];
	while (i < size)
	{
		if (arr[i].price < smallest.price)
		{
			smallest = arr[i];
		}
		i++;
	}
	free(arr);
	return (smallest);
}

t_cheapest	return_cheapest_arr(t_node **head_b, t_node **head_a,
		t_node **tail_a, t_node **tail_b)
{
	t_cheapest	*arr_a;
	t_cheapest	*arr_rev;
	t_cheapest	cheapest;
	t_cheapest	cheapest1;
	t_cheapest	cheapest2;

	arr_a = find_cheapest_path_a(head_b, head_a, tail_a, tail_b);
	arr_rev = find_cheapest_path_rev_a(head_b, head_a, tail_a, tail_b);
	cheapest1 = find_cheapest_arr(arr_a, head_b);
	cheapest2 = find_cheapest_arr(arr_rev, head_b);
	if (cheapest1.price <= cheapest2.price)
	{
		cheapest = cheapest1;
		cheapest.dir = RB;
	}
	else
	{
		cheapest = cheapest2;
		cheapest.dir = RRB;
	}
	return (cheapest);
}

t_cheapest	price_calc(t_cheapest arr)
{
	t_cheapest	stack;

	stack = arr;
	if (arr.iterations >= arr.other_r)
		stack.price = arr.iterations;
	else
		stack.price = arr.other_r;
	return (stack);
}
