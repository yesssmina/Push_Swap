/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 04:09:49 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/30 17:59:17 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_node **pileB)
{
	t_node	*ultime_node;
	t_node	*before_last;

	if (*pileB && (*pileB)->next)
	{
		ultime_node = NULL;
		before_last = *pileB;
		

		while (before_last->next->next != NULL)
		{
			before_last = before_last->next;
		}

		ultime_node = before_last->next;
		before_last->next = NULL; //detachement dernier noeud
		ultime_node->prev = NULL;

		ultime_node->next = *pileB;
		(*pileB)->prev = ultime_node;
		*pileB = ultime_node;
		ft_putstr_fd("rrb\n", 1);
	}
}