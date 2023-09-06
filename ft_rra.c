/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 03:08:03 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:15:56 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_node **pile_a)
{
	t_node	*ultime_node;
	t_node	*before_last;

	if (*pile_a && (*pile_a)->next)
	{
		ultime_node = NULL;
		before_last = *pile_a;
		while (before_last->next->next != NULL)
			before_last = before_last->next;
		ultime_node = before_last->next;
		before_last->next = NULL;
		ultime_node->prev = NULL;
		ultime_node->next = *pile_a;
		(*pile_a)->prev = ultime_node;
		*pile_a = ultime_node;
		ft_putstr_fd("rra\n", 1);
	}
}

void	twice_rra(t_node **pile_a)
{
	ft_rra(pile_a);
	ft_rra(pile_a);
}
