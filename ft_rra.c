/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:08:03 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 18:34:20 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **pileA)
{
	t_node	*ultime_node;
	t_node	*before_last;

	if (*pileA && (*pileA)->next)
	{
		ultime_node = NULL;
		before_last = *pileA;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		ultime_node = before_last->next;
		before_last->next = NULL;
		ultime_node->prev = NULL;
		ultime_node->next = *pileA;
		(*pileA)->prev = ultime_node;
		*pileA = ultime_node;
		ft_putstr_fd("rra\n", 1);
	}
}

void	twice_rra(t_node **pileA)
{
	ft_rra(pileA);
	ft_rra(pileA);
}
