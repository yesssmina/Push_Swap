/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:14:19 by sanaggar          #+#    #+#             */
/*   Updated: 2023/09/06 03:47:57 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_node **pileA, t_node **pileB)
{
	t_node	*tmp;

	tmp = NULL;
	if (*pileA)
	{
		tmp = *pileA;
		*pileA = (*pileA)->next;
		tmp->next = *pileB;
		*pileB = tmp;
		ft_putstr_fd("pb\n", 1);
	}
}
