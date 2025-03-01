/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:31 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:50:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **head_a, t_node **tail_a, char flag)
{
	if (*head_a == *tail_a)
		return ;
	else
	{
		*head_a = *tail_a;
		*tail_a = (*tail_a)->prev;
		(*tail_a)->next = *head_a;
		(*head_a)->prev = *tail_a;
	}
	if (flag == 's')
		write(1, "rra\n", 4);
}

void	rrb(t_node **head_b, t_node **tail_b, char flag)
{
	if (*head_b == *tail_b)
		return ;
	else
	{
		*head_b = *tail_b;
		*tail_b = (*tail_b)->prev;
		(*tail_b)->next = *head_b;
		(*head_b)->prev = *tail_b;
	}
	if (flag == 's')
		write(1, "rrb\n", 4);
}

void	rrr(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
	rra(head_a, tail_a, 'n');
	rrb(head_b, tail_b, 'n');
	write(1, "rrr\n", 4);
}
