/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:37:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 15:59:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **head, t_node **tail)
{
	t_node	*current;
	t_node	*temp;

	if (!head || !*head)
		return ;
	current = *head;
	while (current)
	{
		temp = current->next;
		free(current);
		if (temp == *head)
			break ;
		current = temp;
	}
	*head = NULL;
	*tail = NULL;
}

void	free_split_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	find_largest_elements_position(t_node *head)
{
	t_node	*current;
	t_node	*largest_element;
	int		index;
	int		largest_position;

	current = head;
	largest_element = head;
	index = 0;
	largest_position = 0;
	while (current->next != head)
	{
		if (current->value > largest_element->value)
		{
			largest_element = current;
			largest_position = index;
		}
		current = current->next;
		index++;
	}
	if (current->value > largest_element->value)
	{
		largest_element = current;
		largest_position = index;
	}
	return (largest_position);
}

int	find_smallest_elements_position(t_node *head)
{
	t_node	*smallest_element;
	t_node	*current;
	int		index;
	int		smallest_position;

	smallest_element = head;
	current = head;
	index = 0;
	smallest_position = 0;
	while (current->next != head)
	{
		if (current->value < smallest_element->value)
		{
			smallest_element = current;
			smallest_position = index;
		}
		current = current->next;
		index++;
	}
	if (current->value < smallest_element->value)
	{
		smallest_element = current;
		smallest_position = index;
	}
	return (smallest_position);
}

void	bubble_up_a(t_node **head_a, t_node **tail_a)
{
	int	stack_len;
	int	smallest_elements_position;
	int	reverse_moves;

	stack_len = stack_length(*head_a);
	smallest_elements_position = find_smallest_elements_position(*head_a);
	reverse_moves = stack_len - smallest_elements_position;
	if (smallest_elements_position > stack_len / 2)
	{
		while (reverse_moves--)
			rra(head_a, tail_a, 's');
	}
	else
	{
		while (smallest_elements_position--)
			ra(head_a, tail_a, 's');
	}
}
