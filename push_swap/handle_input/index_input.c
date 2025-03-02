/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:36:02 by codespace         #+#    #+#             */
/*   Updated: 2025/03/02 16:36:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_input(t_node **head_a, int size)
{
	t_node	*current;
	int		*arr;
	int		i;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return ;
	current = *head_a;
	i = 0;
	while (i != size)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	arr = sort_arr(arr, size);
	indexing(arr, head_a, size);
}

int	*sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	indexing(int *arr, t_node **head_a, int size)
{
	t_node	*current;
	int		i;
	int		j;

	current = *head_a;
	i = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == arr[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		j++;
		current = current->next;
	}
	free(arr);
}
