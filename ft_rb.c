/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:48:43 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 03:51:02 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_node **pileB)
{
	t_node	*first_node;
	t_node	*last_node;

	if (*pileB && (*pileB)->next)
	{
		first_node = *pileB;
		*pileB = first_node->next;
		(*pileB)->prev = NULL;
		last_node = *pileB;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = first_node;
		first_node->prev = last_node;
		first_node->next = NULL;
		ft_putstr_fd("rb\n", 1);
	}
}
