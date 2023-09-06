/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:14:19 by sanaggar          #+#    #+#             */
/*   Updated: 2023/09/06 19:16:10 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb(t_node **pile_a, t_node **pile_b)
{
	t_node	*tmp;

	tmp = NULL;
	if (*pile_a)
	{
		tmp = *pile_a;
		*pile_a = (*pile_a)->next;
		tmp->next = *pile_b;
		*pile_b = tmp;
		ft_putstr_fd("pb\n", 1);
	}
}
