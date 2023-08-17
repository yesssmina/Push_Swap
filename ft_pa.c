/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:43:12 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/17 16:29:25 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_pa(t_node **pileA, t_node **pileB)
{
	int	value;
	t_node	*tmp;
	t_node	*new_node;

	if (*pileB)
	{
		value = (*pileB)->value; //valeur sommet B
		tmp = *pileB; //stock pointeur sommet B

		*pileB = (*pileB)->next; // deplace pointeur sommet au 2e element
		free(tmp); //libere 1er maillon B

		// Ajoute 1er maillon a A
		new_node = malloc(sizeof(t_node));
		new_node->value = value;
		new_node->next = *pileA;
		*pileA = new_node;

	}
	return (*pileA);
}