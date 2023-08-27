/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:48:43 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/22 18:49:27 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_node **pileB)
{
	if (*pileB && (*pileB)->next)
	{
		t_node	*first_node;
		t_node	*last_node;

		first_node = *pileB;
		*pileB = first_node->next; // deplacement pointeur 2e noeud
		(*pileB)->prev = NULL;

		last_node = *pileB;

		while (last_node->next)
			last_node = last_node->next;


		last_node->next = first_node;
		first_node->prev = last_node;
		first_node->next = NULL; // le 1er noeud deplace est mtn le dernier

	}
}
