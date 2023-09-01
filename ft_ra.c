/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:15:12 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/01 18:59:24 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **pileA)
{
	if (*pileA && (*pileA)->next)
	{
		t_node	*first_node;
		t_node	*last_node;

		first_node = *pileA;
		*pileA = first_node->next; // deplacement pointeur 2e noeud
		(*pileA)->prev = NULL;

		last_node = *pileA;

		while (last_node->next)
			last_node = last_node->next;


		last_node->next = first_node;
		first_node->prev = last_node;
		first_node->next = NULL; // le 1er noeud deplace est mtn le dernier

		ft_putstr_fd("ra\n", 1);
	}
}
