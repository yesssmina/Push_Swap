/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:08:03 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/18 04:08:51 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_node **begin, int value)
{
	t_node  *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;

	new_node->value = value;
	new_node->next = *begin;
	*begin = new_node;
}


void	ft_rra(t_node **pileA)
{
	t_node	*ultime_node;
	t_node	*before_last;

	if (*pileA && (*pileA)->next)
	{
		before_last = *pileA;
		ultime_node = NULL;

		while (before_last->next->next != NULL)
		{
			before_last = before_last->next;
		}

		ultime_node = before_last->next;
		before_last->next = NULL; //detachement dernier noeud

		add_front(pileA, ultime_node->value);

		free(ultime_node);

	}
}