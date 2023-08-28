/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:10:27 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/28 22:55:14 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error_double(t_node *pileA)
{
	t_node	*doublon;
	t_node	*tmp;

	doublon = pileA;

	while (doublon)
	{
		tmp = doublon->next;

		while (tmp)
		{
			if (doublon->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		doublon = doublon->next;
	}
	return (0);
}

void   add_back(t_node **begin, int value)
{
	t_node  *current;
	t_node  *new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;

	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*begin == NULL)  // Si la liste est vide, ajoute le premier nœud
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

t_node	*plus_petit_node(t_node *pileA)
{
	t_node	*plus_petit;

	plus_petit = pileA;

	while (pileA)
	{
		if (pileA->value < plus_petit->value)
			plus_petit = pileA;
		pileA = pileA->next;
	}
	return (plus_petit);
}

int	size_pileA(t_node *pileA)
{
	int		size;
	t_node	*tmp;

	size = 0;
	tmp = pileA;

	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	smallest_place(t_node *pileA, t_node *smallest)
{
	t_node	*list;
	int		smallest_place;

	smallest_place = 1;
	list = pileA;

	while (list)
	{
		if (list->value == smallest->value)
			return (smallest_place);

		smallest_place++;
		list = list->next;
	}
	return (0);
}

int	biggest_place(t_node *pileB, t_node *biggest)
{
	t_node	*list;
	int		biggest_place;

	biggest_place = 1;
	list = pileB;

	while (list)
	{
		if (list->value == biggest->value)
			return (biggest_place);

		biggest_place++;
		list = list->next;
	}
	return (0);
}