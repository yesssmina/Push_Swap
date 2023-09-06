/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:15:12 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:15:56 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **pile_a)
{
	t_node	*first_node;
	t_node	*last_node;

	if (*pile_a && (*pile_a)->next)
	{
		first_node = *pile_a;
		*pile_a = first_node->next;
		(*pile_a)->prev = NULL;
		last_node = *pile_a;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = first_node;
		first_node->prev = last_node;
		first_node->next = NULL;
		ft_putstr_fd("ra\n", 1);
	}
}

void	twice_ra(t_node **pile_a)
{
	ft_ra(pile_a);
	ft_ra(pile_a);
}
