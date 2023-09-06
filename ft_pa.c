/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:43:12 by sannagar          #+#    #+#             */
/*   Updated: 2023/09/06 03:46:24 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_node **pileA, t_node **pileB)
{
	int		value;
	t_node	*tmp;
	t_node	*new_node;

	if (*pileB)
	{
		value = (*pileB)->value;
		tmp = *pileB;
		*pileB = (*pileB)->next;
		free(tmp);
		new_node = malloc(sizeof(t_node));
		new_node->value = value;
		new_node->next = *pileA;
		*pileA = new_node;
		ft_putstr_fd("pa\n", 1);
	}
}
