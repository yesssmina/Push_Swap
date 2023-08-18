/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 04:09:49 by sannagar          #+#    #+#             */
/*   Updated: 2023/08/18 04:12:22 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_node **pileB)
{
	t_node	*ultime_node;
	t_node	*before_last;

	if (*pileB && (*pileB)->next)
	{
		before_last = *pileB;
		ultime_node = NULL;

		while (before_last->next->next != NULL)
		{
			before_last = before_last->next;
		}

		ultime_node = before_last->next;
		before_last->next = NULL; //detachement dernier noeud

		add_front(pileB, ultime_node->value);

		free(ultime_node);

	}
}