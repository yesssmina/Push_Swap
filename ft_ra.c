/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:15:12 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/17 17:49:24 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **pileA)
{
	if (*pileA && (*pileA)->next)
	{
		t_node	*first_node;

		first_node = *pileA;

		*pileA = (*pileA)->next; // deplacement pointeur 2e noeud
		first_node->next = NULL; // detache le 1er noeud du reste de la liste

		add_back(pileA, first_node->value); // Ajouter le premier nœud à la fin de la pile

		free(first_node);
	}
}
