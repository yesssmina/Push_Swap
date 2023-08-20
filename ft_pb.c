/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:14:19 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/20 20:01:29 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//void	ft_pb(t_node **pileA, t_node **pileB)
//{
//	int	value;
//	t_node	*tmp;
//	t_node	*new_node;

//	if (*pileA)
//	{
//		value = (*pileA)->value; //valeur sommet B
//		tmp = *pileA; //stock pointeur sommet B

//		*pileA = (*pileA)->next; // deplace pointeur sommet au 2e element
//		free(tmp); //libere 1er maillon B

//		// Ajoute 1er maillon a A
//		new_node = malloc(sizeof(t_node));
//		new_node->value = value;
//		new_node->next = *pileB;
//		*pileB = new_node;

//	}
//}

void ft_pb(t_node **pileA, t_node **pileB)
{
	t_node	*tmp;

	tmp = NULL;
	
    if (*pileA)
    {
        tmp = *pileA;
        *pileA = (*pileA)->next;
        
        tmp->next = *pileB; // Lie le nœud temporaire au début de la pile B
        *pileB = tmp; // Mise a jour du pointeur de pile B
    }
}