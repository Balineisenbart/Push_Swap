/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:36 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 15:52:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **head_a, t_node **tail_a, char flag)
{
	t_node	*temp;

	if ((*head_a)->next == *tail_a)
	{
		temp = *tail_a;
		*tail_a = *head_a;
		*head_a = temp;
	}
	else
	{
		temp = *head_a;
		*head_a = (*head_a)->next;
		temp->next = (*head_a)->next;
		(*head_a)->next->prev = temp;
		(*head_a)->next = temp;
		temp->prev = *head_a;
		(*tail_a)->next = *head_a;
		(*head_a)->prev = *tail_a;
	}
	if (flag == 's')
		write(1, "sa\n", 3);
}
