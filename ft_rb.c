/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:48:43 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:10 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_node **pile_b)
{
	t_node	*first_node;
	t_node	*last_node;

	if (*pile_b && (*pile_b)->next)
	{
		first_node = *pile_b;
		*pile_b = first_node->next;
		(*pile_b)->prev = NULL;
		last_node = *pile_b;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = first_node;
		first_node->prev = last_node;
		first_node->next = NULL;
		ft_putstr_fd("rb\n", 1);
	}
}
