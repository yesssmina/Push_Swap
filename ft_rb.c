/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:48:43 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/17 17:51:50 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_node **pileB)
{
	if (*pileB && (*pileB)->next)
	{
		t_node	*first_node;

		first_node = *pileB;

		*pileB = (*pileB)->next; // deplacement pointeur 2e noeud
		first_node->next = NULL; // detache le 1er noeud du reste de la liste
		
		add_back(pileB, first_node->value); // Ajouter le premier nœud à la fin de la pile

		free(first_node);
	}
}
