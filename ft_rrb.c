/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 04:09:49 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:10 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_node **pile_b)
{
	t_node	*ultime_node;
	t_node	*before_last;

	if (*pile_b && (*pile_b)->next)
	{
		ultime_node = NULL;
		before_last = *pile_b;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		ultime_node = before_last->next;
		before_last->next = NULL;
		ultime_node->prev = NULL;
		ultime_node->next = *pile_b;
		(*pile_b)->prev = ultime_node;
		*pile_b = ultime_node;
		ft_putstr_fd("rrb\n", 1);
	}
}
