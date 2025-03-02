/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:28 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:51:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
	t_node	*temp;

	if (!*head_a)
		return ;
	temp = maintain_circularity(head_a, tail_a);
	push_to_other_stack(head_b, tail_b, temp);
	write(1, "pb\n", 3);
}

void	pa(t_node **head_a, t_node **tail_a, t_node **head_b, t_node **tail_b)
{
	t_node	*temp;

	if (!*head_b)
		return ;
	temp = maintain_circularity(head_b, tail_b);
	push_to_other_stack(head_a, tail_a, temp);
	write(1, "pa\n", 3);
}

t_node	*maintain_circularity(t_node **head, t_node **tail)
{
	t_node	*temp;

	temp = *head;
	if (*head == *tail)
	{
		*head = NULL;
		*tail = NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		*head = temp->next;
	}
	return (temp);
}

void	push_to_other_stack(t_node **head_other, t_node **tail_other,
		t_node *temp)
{
	if (*head_other == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		*head_other = temp;
		*tail_other = temp;
	}
	else
	{
		temp->next = *head_other;
		temp->prev = *tail_other;
		(*head_other)->prev = temp;
		(*tail_other)->next = temp;
		*head_other = temp;
	}
	temp = NULL;
}
