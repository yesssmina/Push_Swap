/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:10:27 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/09 18:08:53 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back(t_node **begin, int value)
{
	t_node	*current;
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_mess("Error\nL'allocation de 'new_node' a echouee\n");
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*begin == NULL)
	{
		*begin = new_node;
		return ;
	}
	current = *begin;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

t_node	*plus_petit_node(t_node *pile_a)
{
	t_node	*plus_petit;

	plus_petit = pile_a;
	while (pile_a)
	{
		if (pile_a->value < plus_petit->value)
			plus_petit = pile_a;
		pile_a = pile_a->next;
	}
	return (plus_petit);
}

int	size_pile(t_node *pile_a)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = pile_a;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	smallest_place(t_node *pile_a, t_node *smallest)
{
	t_node	*list;
	int		smallest_place;

	smallest_place = 1;
	list = pile_a;
	while (list)
	{
		if (list->value == smallest->value)
			return (smallest_place);
		smallest_place++;
		list = list->next;
	}
	return (0);
}

int	biggest_place(t_node *pile_b, t_node *biggest)
{
	t_node	*list;
	int		biggest_place;

	biggest_place = 1;
	list = pile_b;
	while (list)
	{
		if (list->value == biggest->value)
			return (biggest_place);
		biggest_place++;
		list = list->next;
	}
	return (0);
}
