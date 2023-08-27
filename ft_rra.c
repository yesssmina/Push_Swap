/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:08:03 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/22 18:56:10 by sannagar         ###   ########.fr       */
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
	new_node->prev = NULL;

	if (*begin != NULL)
		(*begin)->prev = new_node;
		
	*begin = new_node;
}


void	ft_rra(t_node **pileA)
{
	t_node	*ultime_node;
	t_node	*before_last;

	if (*pileA && (*pileA)->next)
	{
		ultime_node = NULL;
		before_last = *pileA;
		

		while (before_last->next->next != NULL)
		{
			before_last = before_last->next;
		}

		ultime_node = before_last->next;
		before_last->next = NULL; //detachement dernier noeud
		ultime_node->prev = NULL;

		ultime_node->next = *pileA;
		(*pileA)->prev = ultime_node;
		*pileA = ultime_node;

		//free(ultime_node);

	}
}