/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:11:53 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/20 20:00:32 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	//printf("plus petit:%d\n", plus_petit->value);
	return (plus_petit);
}


void	sort(t_node **pileA, t_node **pileB)
{
	t_node	*smallest;


	while (*pileA != NULL)
	{
		smallest = plus_petit_node(*pileA);
		
		while ((*pileA)->value != smallest->value)
			ft_ra(pileA);

		ft_pb(pileA, pileB);
	}
}